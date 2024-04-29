#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include "filestatus.h"
#include <QObject>
#include <QList>


class FileMonitor : public QObject
{
private:
    Q_OBJECT
    QList<FileStatus> objects;

    FileMonitor(){}
    ~FileMonitor(){}
    FileMonitor(FileMonitor const &);
    FileMonitor& operator=(FileMonitor const&);
public:
    static FileMonitor& Instance()
    {
        static FileMonitor s;
        return s;
    }
    bool AddFile(QString path);
    bool DelFile(QString path);
signals:
    void Resized(QString path, qint64 size);
    void Exist(QString path,qint64 size);
    void NotExist(QString path);
    void FirstOut(QString path,qint64 size,bool isExisting);

public slots:
    void update();
};

#endif // FILEMONITOR_H
