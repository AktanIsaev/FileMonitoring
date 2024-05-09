#ifndef FILESTATUS_H
#define FILESTATUS_H

#include <QString>
#include <QFileInfo>

class FileStatus // класс инфы о файле
{
    QString FilePath; // путь
    qint64 Size; // размер
    bool IsExisting; // факт существования
public:
    FileStatus(); // конструктор по умлочанию
    FileStatus(QString path); // конструктор с параметром
    bool operator==(const FileStatus& other) const; // оператор сравнения
    bool update(); // обновление информации о файле

    // получить
    QString GetFilePath(); // путь
    qint64 GetSize(); // размер
    bool GetIsExisting(); // факт существования
public:
    FileStatus(const FileStatus& other); // конструктор копирования
};
#endif // FILESTATUS_H
