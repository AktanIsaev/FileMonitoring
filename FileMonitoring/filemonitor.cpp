#include "filemonitor.h"

bool FileMonitor::AddFile(QString path)
{
    FileStatus temp(path); //временный файл для проверки на наличие файла в списке
    if(objects.contains(temp))
    {
        return false;
    }
    objects.push_back(temp);
    emit FirstOut(temp.GetFilePath(), temp.GetSize(), temp.GetIsExisting());
    return true;
}

bool FileMonitor::DelFile(QString path)//удаление файла
{
    FileStatus temp(path);
    if(objects.contains(temp))
    {
        objects.removeOne(temp);
        return true;
    }
    return false;
}

void FileMonitor::update()//обновление информации о файлах
{

}

