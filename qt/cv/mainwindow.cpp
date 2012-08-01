#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "convertimage.h"
#include <QtCore>
#include <QtGui>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load("a1.jpg");
    loadDlg("a2.jpg");
    loadDlg("a3.jpg");
    loadDlg("a4.jpg");
    loadDlg("a5.jpg");
    loadDlg("a6.png");
    loadDlg("a10.jpg");
    loadDlg("a11.jpg");
    loadDlg("a12.jpg");
    loadDlg("a13.jpg");
    activateWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load(char const *file)
{
    QImage img;
    QPixmap pm;
    pm.load(file);
    if (!pm.isNull()) {
        QPixmap pm2(pm.width() + ((pm.width() % 4) ?  4 - (pm.width() % 4) : 0), pm.height());
        QPainter painter(&pm2);
        painter.drawPixmap(0, 0, pm);
        img = pm2.toImage();
        if (!img.isNull()) {
            QImage img2 = ConvertImage::gray(&img);
            ui->label->setPixmap(QPixmap::fromImage(img2));
        }
    }
}

void MainWindow::loadDlg(const char *file)
{
    QImage img;
    QPixmap pm;
    pm.load(file);
    if (!pm.isNull()) {
        QPixmap pm2(pm.width() + ((pm.width() % 4) ?  4 - (pm.width() % 4) : 0), pm.height());
        QPainter painter(&pm2);
        painter.drawPixmap(0, 0, pm);
        img = pm2.toImage();
        if (!img.isNull()) {
            QImage img2 = ConvertImage::sepia(&img);
            Dialog *dlg = new Dialog(this);
            dlg->set(QPixmap::fromImage(img));
            dlg->show();
        }
    }
}
