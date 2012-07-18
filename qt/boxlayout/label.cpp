#include "label.h"
#include <QDebug>

Label::Label(QString name, QWidget *parent) :
    QLabel(parent)
{
    this->name = name;
    qDebug() << name << this;
}

Label::~Label()
{
    qDebug() << "~Label" << name << parent();
}

QString Label::getName()
{
    return name;
}
