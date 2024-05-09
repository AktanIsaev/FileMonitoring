#ifndef OUTPUTDISPLAY_H
#define OUTPUTDISPLAY_H

#include <QObject>
#include <QTextStream>
#include <iostream>

class OutputDisplay : public QObject // класс вывода
{
    Q_OBJECT // для корректной работы механизма сигналов и слотов
public slots:
    //слоты для вывода информации
    void displayExistingFile(QString temp, qint64 size); // существование файла
    void displayNonExistingFile(QString temp); // отсутствие файла
    void displayResizedFile(QString temp, qint64 size); // изменение размера
    void FirstDisplay(QString path, qint64 size, bool isExisting); // первое обнаружение
};

#endif // OUTPUTDISPLAY_H
