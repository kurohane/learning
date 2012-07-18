#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include "hbox.h"
#include "label.h"

/*
 * l3とL5がh2削除時に削除されないのは若干不思議
 * addWidgetで登録された場合、親はレイアウトの親ウィジェットになる
 * レイアウトに親がウィジェットがない場合は親設定されないが、レイアウトの親ウィジェットが設定されたタイミングで子の親ウィジェット設定が行われる（謎）
 * せめて親が設定されていないオブジェクトに限定しなかった理由を知りたい
 * 参照カウンタにより所有者が複数になった為に参照カウンタが０になるタイミングで解放されるのかとも思ったがやはり親の付け替えが暗黙で行われている
 * 参照カウンタによる管理が行われているかは調査していない(ヤル気があるときにやろうかな。。。)
 * 暗黙の親付け替えが行われるので、parent関数で想定通りの親が取得できるという設計は危険。派生クラスで必要なクラスポインタをメンバ変数にもつ
*/

MainWindow::MainWindow(QString name, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug() << name << this;
    ui->setupUi(this);
    this->name = name;
    HBox *hbox = new HBox("h1");
    hbox->addWidget(new Label("l1"));
    hbox->addWidget(new Label("l2"));
    ui->vbox->addLayout(hbox);
    HBox *hbox2 = new HBox("h2");
    hbox2->addWidget(new Label("l3"));
    Label *w = new Label("l4");
    Label *l = new Label("l5", w);
    qDebug() << "l5 parent addWidget before" << l->parent();
    hbox2->addWidget(l);
    qDebug() << "l5 parent addWidget after" << l->parent();
    Label *l2 = new Label("l6", w);
    qDebug() << "l5 parent" << l->parent() << __LINE__;
    Label *l3 = new Label("l7");
    qDebug() << "l5 parent" << l->parent() << __LINE__;
    ui->vbox->addLayout(hbox2);
    qDebug() << "l5 parent" << l->parent() << __LINE__;
    hbox->removeWidget(l);
    qDebug() << "l5 parent" << l->parent() << __LINE__;
    delete hbox;
    qDebug() << "l5 parent" << l->parent() << __LINE__;
    qDebug() << "delete l4 l5 parent addWidget before" << l->parent();
    delete w;
    qDebug() << "delete l4 l5 parent addWidget after" << l->parent();
}

MainWindow::~MainWindow()
{
    qDebug() << "~MainWindow" << name << parent();
    delete ui;
}

QString MainWindow::getName()
{
    return name;
}
