#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    fsmodel = new QFileSystemModel;
    fsmodel->setRootPath(QDir::currentPath());
    ui->treeView->setModel(fsmodel);
    ui->treeView->setColumnHidden(1, true);
    ui->treeView->setColumnHidden(2, true);
    ui->treeView->setColumnHidden(3, true);
    ui->treeView->expandAll();
    ui->listView->setModel(fsmodel);

    file = new File("cash", this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_treeView_clicked(const QModelIndex &index)
{
    ui->listView->setRootIndex(index);
}

void Dialog::on_pushButton_clicked()
{
    add();
}

void Dialog::on_pushButton_2_clicked()
{
    int i;
    for (i = 0; i < 1000; ++i) {
        add();
    }
}


void Dialog::add()
{
    static int num = 0;
    QString fname = QString("test%1.txt").arg(num);
    file->save(fname);
    ++num;
}

void Dialog::on_pushButton_3_clicked()
{
    int i;
    for (i = 0; i < 10000; ++i) {
        add();
    }
}

void Dialog::on_pushButton_4_clicked()
{
    int i;
    int num = ui->spinBox->value();
    for (i = 0; i < num; ++i) {
        add();
    }
}

void Dialog::on_pushButton_5_clicked()
{
    file->clear();
}
