#include "outputdisplay.h"

void OutputDisplay::displayExistingFile(QString temp, qint64 size)//вывод на консоль если файл существует
{
    std::cout << "File " << temp.toStdString().c_str() << " exists, size: " << size << std::endl;
}

void OutputDisplay::displayNonExistingFile(QString temp)//вывод на консоль если файл не существует
{
    std::cout << "File " << temp.toStdString().c_str() << " does not exist" << std::endl;
}

void OutputDisplay::displayResizedFile(QString temp, qint64 size)//вывод на консоль если файл изменил размер
{
    std::cout << "File " << temp.toStdString().c_str() << " changed size, new_size: " << size << std::endl;
}

void OutputDisplay::FirstDisplay(QString path, qint64 size, bool isExisting)//первый вывод информации о файле
{
    if (isExisting)
    {
        std::cout << "File " << path.toStdString().c_str() << " exists, size: " << size << std::endl;
    }
    else
    {
        std::cout << "File " << path.toStdString().c_str() << " does not exist" << std::endl;
    }
}
