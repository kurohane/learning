#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void pfinish(int , QProcess::ExitStatus );
    void output();
    void err();

    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    QProcess proc;
};

#endif // MAINWINDOW_H
