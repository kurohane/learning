#ifndef LABEL_H
#define LABEL_H

#include <QLabel>

class Label : public QLabel
{
    Q_OBJECT
    QString name;
public:
    explicit Label(QString name, QWidget *parent = 0);
    virtual ~Label();
    
signals:
    
public slots:
    
};

#endif // LABEL_H
