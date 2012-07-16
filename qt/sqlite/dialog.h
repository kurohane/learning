#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql/QtSql>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Dialog *ui;
    QSqlDatabase db;

    void update(QString key, QString val);
    void insert(QString key, QString val);
};

#endif // DIALOG_H
