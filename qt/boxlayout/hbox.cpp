#include "hbox.h"
#include <QDebug>

HBox::HBox(QString name, QWidget *parent) :
    QHBoxLayout(parent)
{
    this->name = name;
}

HBox::~HBox()
{
    qDebug() << "~HBox " << name;
}
