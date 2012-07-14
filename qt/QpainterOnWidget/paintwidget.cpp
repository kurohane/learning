#include "paintwidget.h"
#include <QtGui>

PaintWidget::PaintWidget(QWidget *parent) :
    QLabel(parent)
{
    QLabel::setText("aaa");
}

void PaintWidget::paintEvent(QPaintEvent *ev)
{
    QLabel::paintEvent(ev);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3));
    painter.drawRect(20, 30, 30, 40);
}
