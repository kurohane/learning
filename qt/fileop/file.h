#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QtGui>

class File : public QObject
{
    Q_OBJECT

    QString name;
    struct {
        short a;
        short b;
        short c;
    } last;
    void clear(QString target);
public:
    explicit File(QString name, QObject *parent = 0);
    bool save(QString file);
    bool mkpath(QString path);
    void calcLast();
    void clear();
signals:
    
public slots:
    
};

#endif // FILE_H
