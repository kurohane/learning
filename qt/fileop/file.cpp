#include "file.h"
#include <QFile>
#include <QFileInfo>

File::File(QString name, QObject *parent) :
    QObject(parent)
{
    this->name = name;
    memset(&last, 0, sizeof(last));
}


bool File::save(QString file)
{
    QDir d;
    qDebug() << d;
    if (d.mkpath(name)) {
        qDebug("dir create");
    } else {
        qDebug("dir create error");
    }

    QFile f(name + "/" + file);
    if (!f.exists()) {
        f.open(QIODevice::WriteOnly);
        if (f.isOpen()) {
            qDebug("open");
        } else {
            qDebug("open error");
        }
    } else {
        qDebug("exist");
    }
    return true;
}


bool File::mkpath(QString path)
{
    QDir dir;
    if (dir.mkpath(path)) {

    }
    return true;
}


void File::clear(QString target)
{
    QDir dir(target);
    QFile file;
    if (dir.exists()) {
        QFileInfoList l = dir.entryInfoList(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);
        QFileInfo fi;
        foreach (fi, l) {
            if (fi.isDir()) {
                clear(fi.absoluteFilePath());
            } else if (fi.isFile()) {
               file.setFileName(fi.absoluteFilePath());
               if (!file.remove()) {
                   qDebug("remove error");
               }
               qDebug() << "remove" << fi.absoluteFilePath();
            }
        }
        dir.cdUp();
        if (!dir.rmdir(target)) {
            qDebug("rmdir error");
        }
        qDebug() << "rmdir" << target;
    }
}


void File::clear()
{
    clear(name);
}
