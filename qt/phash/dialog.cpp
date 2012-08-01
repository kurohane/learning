#include "dialog.h"
#include "ui_dialog.h"
#include <pHash.h>
#include <iostream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ulong64 hash;
    ph_dct_imagehash("aaa.jpg", hash);
    std::cout << hash << endl;
    QPixmap pm("aaa.jpg");
    ui->label->setPixmap(pm);
}

Dialog::~Dialog()
{
    delete ui;
}
