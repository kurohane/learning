#include "cvimage.h"

CVImage::CVImage(char const *file, QObject *parent) :
    QObject(parent)
{
    img = NULL;
    if (file) {
//        img = cvLoadImage(file);
//        cvDecodeImage(NULL);
//        cv::Mat mat = cv::imread("a1.jpg");
    }
}

CVImage::~CVImage()
{
    if (img) {
        cvReleaseImage(&img);
    }
}

IplImage *CVImage::get()
{
    return img;
}

IplImage *CVImage::create(int width, int height)
{
    return img = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);
}
