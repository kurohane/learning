#include "hbox.h"
#include <QDebug>

HBox::HBox(QString name, QWidget *parent) :
    QHBoxLayout(parent)
{
    this->name = name;
    qDebug() << name << this;
}

HBox::~HBox()
{
    qDebug() << "~HBox" << name << parent();
}

QString HBox::getName()
{
    return name;
}
