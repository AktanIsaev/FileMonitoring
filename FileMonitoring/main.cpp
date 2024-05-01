#include <QCoreApplication>
#include "filemonitor.h"
#include "outputdisplay.h"
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileMonitor& monitor = FileMonitor::Instance();
    OutputDisplay display;
    QObject::connect(&monitor, &FileMonitor::Resized, &display, &OutputDisplay::displayResizedFile);
    QObject::connect(&monitor, &FileMonitor::Exist, &display, &OutputDisplay::displayExistingFile);
    QObject::connect(&monitor, &FileMonitor::NotExist, &display, &OutputDisplay::displayNonExistingFile);
    QObject::connect(&monitor, &FileMonitor::FirstOut, &display, &OutputDisplay::FirstDisplay);
   //добавляем файлы под наблюдение
    monitor.AddFile("C:\\Users\\Aktan\\Desktop\\Новая папка\\A.txt");

    QTimer* timer = new QTimer(&monitor);//добавление таймера и связи м/д сигналом и слотом
    QObject::connect(timer, SIGNAL(timeout()), &monitor, SLOT(update()));
    timer->start(100);
    return a.exec();
}
