#include "filestatus.h"

FileStatus::FileStatus() // конструтор по умолчанию
{
    FilePath = "";
    Size = 0;
    IsExisting = false;
}
FileStatus::FileStatus(QString path) // конструктор с параметром
{
    // инициализация
    QFileInfo file(path); // объекта file
    FilePath = path; // пути
    Size = file.size(); // размера
    IsExisting = file.exists(); // факта существования
}

// получить
QString FileStatus::GetFilePath() // путь
{
    return FilePath;
}
qint64 FileStatus::GetSize() // размер
{
    return Size;
}
bool FileStatus::GetIsExisting() // факт существования
{
    return IsExisting;
}


bool FileStatus::update() // обновление информации о файле
{
    QFileInfo temp = QFileInfo(FilePath); // инициализация временного файла
    if(temp.exists() && !IsExisting) // если temp существует и его не было до
    {
        IsExisting = true;
        Size = temp.size();
        return true;
    }
    else if(!temp.exists() && IsExisting) // если temp не существует и он был до
    {
        IsExisting = false;
        Size = 0;
        return true;
    }
    else if(temp.size()!= Size) // если изменился размер
    {
        Size = temp.size();
        return true;
    }
    return false; // обновление инфы о файле не требуется
}

bool FileStatus::operator==(const FileStatus& other) const // оператор сравнения
{
    return other.FilePath == FilePath && other.Size == Size && other.IsExisting == IsExisting;
}

FileStatus::FileStatus(const FileStatus& other) // конструктор копирования
{
    FilePath = other.FilePath;
    IsExisting = other.IsExisting;
    Size = other.Size;
}
