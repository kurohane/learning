#include "convertimage.h"
//#include "cvimage.h"
#include <QtCore>

namespace ConvertImage{

#define PIXVAL(iplimagep, x, y) (*(uchar *)((iplimagep)->imageData + (y) * (iplimagep)->widthStep + (x)))
#define PIXVALB(iplimagep, x, y) (*(uchar *)((iplimagep)->imageData + (y) * (iplimagep)->widthStep + (x)*3))
#define PIXVALG(iplimagep, x, y) (*(uchar *)((iplimagep)->imageData + (y) * (iplimagep)->widthStep + (x)*3+1))
#define PIXVALR(iplimagep, x, y) (*(uchar *)((iplimagep)->imageData + (y) * (iplimagep)->widthStep + (x)*3+2))

IplImage* QImage2IplImage(QImage const *src) {
    int width = src->width();
    int height = src->height();

//    CVImage cvi;
//    IplImage *ipl = cvi.create(width, height);
    IplImage *ipl = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);
    char *iplBuf = ipl->imageData;

    //Remove alpha channel
    int jump = (src->hasAlphaChannel()) ? 4 : 3;
    jump = 4;

    int i;
    for (int y = 0; y < ipl->height; ++y) {
        QByteArray srcBuf((const char*)src->scanLine(y), src->bytesPerLine());
        for (i = 0; i < srcBuf.size(); i += jump) {
            //Swap from RGB to BGR
            iplBuf[0] = srcBuf[i];
            iplBuf[1] = srcBuf[i+1];
            iplBuf[2] = srcBuf[i+2];
            iplBuf += 3;
        }
    }
    return ipl;
}

QImage IplImage2QImage(IplImage const *src)
{
    int h = src->height;
    int w = src->width;
    int ch = src->nChannels;
    char *data = src->imageData;
    QImage tmp(w, h, QImage::Format_ARGB32);
    int x, y;
    char r, g, b, a;
    for (y = 0; y < h; ++y, data += w * ch) {
        for (x = 0; x < w; ++x) {
            if (ch == 1) {
                r = data[x * ch];
                g = data[x * ch];
                b = data[x * ch];
            } else if (ch == 3 || ch == 4) {
                r = data[x * ch + 2];
                g = data[x * ch + 1];
                b = data[x * ch];
            }

            if (ch == 4) {
                a = data[x * ch + 3];
                tmp.setPixel(x, y, qRgba(r, g, b, a));
            } else {
                tmp.setPixel(x, y, qRgb(r, g, b));
            }
        }
    }
    return tmp;
}

QImage IplImage2QImage2(IplImage const *src) {
    int height = src->height;
    int width = src->width;

    if  (src->depth == IPL_DEPTH_8U && src->nChannels == 3)
    {
        const uchar *qImageBuffer = (const uchar*)src->imageData;
        QImage img(qImageBuffer, width, height, QImage::Format_RGB888);
        return img.rgbSwapped();
    } else if  (src->depth == IPL_DEPTH_8U && src->nChannels == 1){
        const uchar *qImageBuffer = (const uchar*)src->imageData;
        QImage img(qImageBuffer, width, height, QImage::Format_Indexed8);

        QVector<QRgb> colorTable;
        for (int i = 0; i < 256; i++){
            colorTable.push_back(qRgb(i, i, i));
        }
        img.setColorTable(colorTable);
        return img;
    }else{
        qWarning() << "Image cannot be converted.";
        return QImage();
    }
}

QImage gray(QImage const *src) {
    IplImage *ipl = QImage2IplImage(src);
    IplImage *gray = cvCreateImage(cvGetSize(ipl), IPL_DEPTH_8U, 1);
//    cv::Mat mat(ipl, true), mat2(ipl, true);
//    cv::cvtColor(mat, mat2, CV_BGR2GRAY);
//    IplImage *tmp= cvCreateImage(cvGetSize(ipl), IPL_DEPTH_8U, 1);
//    *tmp = mat2;
//    QImage rtn = ConvertImage::IplImage2QImage(tmp);

    const int darkness = 50;

    // グレースケール化
    cvCvtColor(ipl, gray, CV_BGR2GRAY);
    for(int x = 0; x < gray->width; ++x){
        for(int y = 0; y < gray->height; ++y){
            int g = PIXVAL(gray, x, y) - darkness;
            PIXVAL(gray, x, y) = (g > 0)?g:0;
        }
    }
//    cvCvtColor(gray, ipl, CV_GRAY2RGB);
    QImage rtn = ConvertImage::IplImage2QImage(gray);
//    cvReleaseImage(&ipl);
//    cvReleaseImage(&tmp);
    return rtn;
}

QImage sepia(QImage const *src) {
    IplImage *ipl = QImage2IplImage(src);
    IplImage *gray = cvCreateImage(cvGetSize(ipl), IPL_DEPTH_8U, 1);

    const int darkness = 50;

    // グレースケール化
    cvCvtColor(ipl, gray, CV_BGR2GRAY);
    for(int x = 0; x < gray->width; ++x){
        for(int y = 0; y < gray->height; ++y){
            int g = PIXVAL(gray, x, y) - darkness;
            PIXVAL(gray, x, y) = (g > 0)?g:0;
        }
    }
    cvCvtColor(gray, ipl, CV_GRAY2RGB);

    // セピア色をつける
    for(int x = 0; x < ipl->width; ++x){
        for(int y = 0; y < ipl->height; ++y){
            int r = PIXVALR(ipl, x, y)+30;
            int b = PIXVALB(ipl, x, y)-30;
            PIXVALR(ipl, x, y) = (r < 256)? r : 255;
            PIXVALB(ipl, x, y) = (b > 0)  ? b : 0;
        }
    }
    QImage rtn = ConvertImage::IplImage2QImage(ipl);
    cvReleaseImage(&ipl);
//    cvReleaseImage(&gray);
    return rtn;
}

}



