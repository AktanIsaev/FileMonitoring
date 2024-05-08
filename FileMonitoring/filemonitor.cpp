#include "filemonitor.h"
#include <QDebug>
#include <iostream>
using namespace std;

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
        qDebug() << "Deleted file path: " << path;
        return true;
    }
    return false;
}

void FileMonitor::update()//обновление информации о файлах
{
    for(int i = 0; i < objects.size(); i++)
    {
        FileStatus temp = objects[i];
        if (objects[i].update())
        {
            if (temp.GetIsExisting() && !objects[i].GetIsExisting())
            {
                emit NotExist(objects[i].GetFilePath());
            }
            else if (!temp.GetIsExisting() && objects[i].GetIsExisting())
            {
                emit Exist(objects[i].GetFilePath(), objects[i].GetSize());
            }
            else
            {
                emit Resized(objects[i].GetFilePath(), objects[i].GetSize());
            }
        }
    }
}

