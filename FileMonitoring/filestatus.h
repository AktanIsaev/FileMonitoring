#ifndef FILESTATUS_H
#define FILESTATUS_H
#include <QString>
#include <QFileInfo>

class FileStatus
{
    QString FilePath;
    qint64 Size;
    bool IsExisting;
public:
    FileStatus();
    FileStatus(QString path);
    bool operator==(const FileStatus& other) const;
    bool update();

    QString GetFilePath();
    qint64 GetSize();
    bool GetIsExisting();
public:
    FileStatus(const FileStatus& other);
    FileStatus& operator =(const FileStatus& other);

};
#endif // FILESTATUS_H
