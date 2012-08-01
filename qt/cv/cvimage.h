#ifndef CVIMAGE_H
#define CVIMAGE_H

#include <QObject>
#include <opencv2/opencv.hpp>

class CVImage : public QObject
{
    Q_OBJECT

    IplImage *img;
public:
    explicit CVImage(const char *file = NULL, QObject *parent = NULL);
    virtual ~CVImage();

    IplImage *get();
    IplImage *create(int width, int height);

signals:
    
public slots:
    
};

#endif // CVIMAGE_H
