#include "filestatus.h"


FileStatus::FileStatus()
{
    FilePath = "";
    Size = 0;
    IsExisting = false;
}
FileStatus::FileStatus(QString path)
{
    QFileInfo file(path);
    FilePath = path;
    Size = file.size();
    IsExisting = file.exists();
}


QString FileStatus::GetFilePath()
{
    return FilePath;
}
qint64 FileStatus::GetSize()
{
    return Size;
}
bool FileStatus::GetIsExisting()
{
    return IsExisting;
}


bool FileStatus::update()
{
    QFileInfo temp = QFileInfo(FilePath);
    if(temp.exists() && !IsExisting)
    {
        IsExisting = true;
        Size = temp.size();
        return true;
    }
    else if(!temp.exists() && IsExisting)
    {
        IsExisting = false;
        Size = 0;
        return true;
    }
    else if(temp.size()!= Size)
    {
        Size = temp.size();
        return true;
    }
    return false;
}


bool FileStatus::operator==(const FileStatus& other) const
{
    return other.FilePath == FilePath && other.Size == Size && other.IsExisting == IsExisting;
}

// Проверка на самоприсваивание - либо на опратор =
FileStatus& FileStatus::operator =(const FileStatus& other)
{
    if (this == &other)
    {
        return *this;
    }

    FilePath = other.FilePath;
    IsExisting = other.IsExisting;
    Size = other.Size;
    return *this;
}


FileStatus::FileStatus(const FileStatus& other)
{
    FilePath = other.FilePath;
    IsExisting = other.IsExisting;
    Size = other.Size;
}
