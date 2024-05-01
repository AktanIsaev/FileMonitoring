#ifndef OUTPUTDISPLAY_H
#define OUTPUTDISPLAY_H

#include <QObject>
#include <QTextStream>
#include <iostream>

class OutputDisplay : public QObject//класс наследник qobject т.к. работаем с сигналами-слотами
{
    Q_OBJECT
public slots://слоты для вывода информации
    void displayExistingFile(QString temp, qint64 size);
    void displayNonExistingFile(QString temp);
    void displayResizedFile(QString temp, qint64 size);
    void FirstDisplay(QString path, qint64 size, bool isExisting);
};

#endif // OUTPUTDISPLAY_H
