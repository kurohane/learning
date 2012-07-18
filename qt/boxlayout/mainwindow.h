#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString name;
public:
    explicit MainWindow(QString name, QWidget *parent = 0);
    ~MainWindow();
    QString getName();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
