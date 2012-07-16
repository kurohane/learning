#ifndef HBOX_H
#define HBOX_H

#include <QHBoxLayout>

class HBox : public QHBoxLayout
{
    Q_OBJECT
    QString name;
public:
    explicit HBox(QString name, QWidget *parent = 0);
    virtual ~HBox();
    
signals:
    
public slots:
    
};

#endif // HBOX_H
