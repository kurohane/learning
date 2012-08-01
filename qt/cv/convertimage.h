#ifndef CONVERTIMAGE_H
#define CONVERTIMAGE_H

#include <opencv2/opencv.hpp>
#include <QtGui/QImage>

namespace ConvertImage
{
IplImage* QImage2IplImage(QImage const *src);
QImage IplImage2QImage(IplImage const *src);
QImage IplImage2QImage2(IplImage const *src);
QImage gray(QImage const *src);
QImage sepia(QImage const *src);
}

#endif // CONVERTIMAGE_H
