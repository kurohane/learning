#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my.db");
    if (!db.open()) {
        qDebug("db open error");
    }

    QSqlQuery query("create table test1(key, value)");
    QSqlError err = query.lastError();
    qDebug() << err;

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    insert(ui->lineEdit->text(), ui->lineEdit_2->text());
}

void Dialog::on_pushButton_2_clicked()
{
    update(ui->lineEdit_3->text(), ui->lineEdit_4->text());
}

void Dialog::on_pushButton_3_clicked()
{
    ui->plainTextEdit->clear();
    QSqlError err;
    QSqlQuery query("select * from test1");
    err = query.lastError();
    qDebug() << err;

    while (query.next()) {
        ui->plainTextEdit->appendPlainText(query.value(0).toString() + " | " + query.value(1).toString());
    }
}

void Dialog::on_pushButton_5_clicked()
{
    QSqlQuery query;
    query.prepare("delete from test1 where key = ?");
    query.bindValue(0, ui->lineEdit_5->text());
    query.exec();

    QSqlError err = query.lastError();
    qDebug() << err;

}

void Dialog::on_pushButton_6_clicked()
{
    QSqlQuery query;
    query.prepare("select * from test1 where key = ?");
    query.bindValue(0, ui->lineEdit_6->text());
    query.exec();
    QSqlError err = query.lastError();
    qDebug() << err;

    if (query.next()) {
        qDebug("update");
        update(ui->lineEdit_6->text(), ui->lineEdit_7->text());
    } else {
        qDebug("insert");
        insert(ui->lineEdit_6->text(), ui->lineEdit_7->text());
    }

//    QSqlQuery query;
//    query.prepare("insert or replace into test1 (key, value) values(?, ?)");
//    query.bindValue(0, ui->lineEdit_6->text());
//    query.bindValue(1, ui->lineEdit_7->text());
//    query.exec();

//    QSqlError err = query.lastError();
//    qDebug() << err;

}

void Dialog::update(QString key, QString val)
{
//    QString str = "update test1 set value = '" + ui->lineEdit_4->text() + "' where key = '" + ui->lineEdit_3->text() + "'";
//    qDebug() << str;
//    QSqlQuery query(str);
    QSqlQuery query;
    query.prepare("update test1 set value = ? where key = ?");
    query.bindValue(0, val);
    query.bindValue(1, key);
    query.exec();

    QSqlError err = query.lastError();
    qDebug() << err;
}

void Dialog::insert(QString key, QString val)
{
//    QSqlQuery query("insert into test1 values('" + ui->lineEdit->text() + "', '" + ui->lineEdit_2->text() + "')");
    QSqlQuery query;
    query.prepare("insert into test1 (key, value) values(?, ?)");
    query.bindValue(0, key);
    query.bindValue(1, val);
    query.exec();

    QSqlError err = query.lastError();
    qDebug() << err;
}

void Dialog::on_pushButton_7_clicked()
{
    QSqlQuery query("delete from test1");
}
