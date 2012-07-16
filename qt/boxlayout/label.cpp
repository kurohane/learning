#include "label.h"
#include <QDebug>

Label::Label(QString name, QWidget *parent) :
    QLabel(parent)
{
    this->name = name;
}

Label::~Label()
{
    qDebug() << "~Label " << name;
}
