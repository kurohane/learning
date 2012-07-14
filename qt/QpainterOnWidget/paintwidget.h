#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QLabel>

class PaintWidget : public QLabel
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *ev);

signals:
    
public slots:
    
};

#endif // PAINTWIDGET_H
