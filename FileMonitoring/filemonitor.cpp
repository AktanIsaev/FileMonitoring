#include "filemonitor.h"
#include <QDebug>

bool FileMonitor::AddFile(QString path) // добавление файла в монитор
{
    FileStatus temp(path); // временный объект для проверки
    if(objects.contains(temp)) // если файл содержится в контейнере
    {
        return false;
    }
    objects.push_back(temp); // добавляем в конец контейнера
    emit FirstOut(temp.GetFilePath(), temp.GetSize(), temp.GetIsExisting()); // генерируем сигнал с инфой
    return true;
}

bool FileMonitor::DelFile(QString path) // удаление файла из монитора
{
    FileStatus temp(path); // временный объект для проверки
    if(objects.contains(temp))// если файл содержится в контейнере
    {
        objects.removeOne(temp); // удаляем с контейнера
        qDebug() << "Deleted file path: " << path; // сообщение об удалении из монитора
        return true;
    }
    return false;
}

void FileMonitor::update() // обновление информации о файлах
{
    for(int i = 0; i < objects.size(); i++) // проход по файлам в контейнере
    {
        FileStatus temp = objects[i]; // временный объект для проверки
        if (objects[i].update()) // если файл был обновлен
        {
            if (temp.GetIsExisting() && !objects[i].GetIsExisting()) // если файл был и его нет после обновления
            {
                emit NotExist(objects[i].GetFilePath()); // испускаем сигнал о несуществовании
            }
            else if (!temp.GetIsExisting() && objects[i].GetIsExisting()) // если файла не было и после обновления он есть
            {
                emit Exist(objects[i].GetFilePath(), objects[i].GetSize()); // испускаем сигнал о существовании
            }
            else // если изменился размер
            {
                emit Resized(objects[i].GetFilePath(), objects[i].GetSize()); // испускаем сигнал о изменении размера
            }
        }
    }
}

