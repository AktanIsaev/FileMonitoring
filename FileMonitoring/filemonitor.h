#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include "filestatus.h"
#include <QObject>
#include <QList>

class FileMonitor : public QObject // класс мониторинга файлов
{
private:
    Q_OBJECT // для корректной работы механизма сигналов и слотов
    QList<FileStatus> objects; // контейнер для файлов

    FileMonitor(){} // конструктор по умолчанию
    ~FileMonitor(){} // диструктор
    // FileMonitor(FileMonitor const &);
    // FileMonitor& operator=(FileMonitor const&);
public:
    static FileMonitor& Instance() // статический метод
    {
        static FileMonitor s;
        return s;
    }
    bool AddFile(QString path); // добавлениие файла в монитор
    bool DelFile(QString path); // удаление файла из монитора
signals:
    void Resized(QString path, qint64 size); // изменение размера файла
    void Exist(QString path,qint64 size); // существования файла
    void NotExist(QString path); // отсутствие файла
    void FirstOut(QString path,qint64 size,bool isExisting); // первое обнаружение

public slots:
    void update(); // обновление монитора
};

#endif // FILEMONITOR_H
