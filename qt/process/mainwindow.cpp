#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&proc, SIGNAL(readyReadStandardOutput()), this, SLOT(output()));
    connect(&proc, SIGNAL(readyReadStandardError()), this, SLOT(err()));
    connect(&proc, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(pfinish(int,QProcess::ExitStatus)));
    proc.start("nslookup");
}

MainWindow::~MainWindow()
{
    proc.close();
    delete ui;
}

void MainWindow::pfinish(int, QProcess::ExitStatus)
{
    close();
}

void MainWindow::output()
{
    QString out = QString::fromLocal8Bit(proc.readAllStandardOutput());
    ui->textEdit->insertPlainText(out); // appendだと改行が追加されてしまう
}

void MainWindow::err()
{
    ui->textEdit->insertPlainText(QString::fromLocal8Bit(proc.readAllStandardError()));
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString input = ui->lineEdit->text() + "\n";
    ui->textEdit->insertPlainText(input);
    proc.write(input.toLocal8Bit());
}
