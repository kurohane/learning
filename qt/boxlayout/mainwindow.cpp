#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include "hbox.h"
#include "label.h"

/*
 * l3とL5がh2削除時に削除されないのは若干不思議
 * addWidgetで登録された場合、親はトップレベルウィンドウになる？
 * l5の親がaddWidget時にl4から移っているのも興味深い
 * parant指定しなくてもトップレベルウィンドウに連動するかと思ったがl7がリークしているのでそれはない
*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    HBox *hbox = new HBox("h1");
    hbox->addWidget(new Label("l1"));
    hbox->addWidget(new Label("l2"));
    ui->vbox->addLayout(hbox);
    HBox *hbox2 = new HBox("h2");
    hbox2->addWidget(new Label("l3"));
    Label *w = new Label("l4");
    Label *l = new Label("l5", w);
    hbox2->addWidget(l);
    Label *l2 = new Label("l6", w);
    Label *l3 = new Label("l7");
    ui->vbox->addLayout(hbox2);
    hbox->removeWidget(l);
    delete hbox;
    delete w;
}

MainWindow::~MainWindow()
{
    qDebug("~MainWindow");
    delete ui;
}
