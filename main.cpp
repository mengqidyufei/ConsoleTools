#include <QCoreApplication>
#include <QDebug>
#include "EnumBool.h"
#include "SortItemList.h"
#include <QPolygonF>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Hello Console";
    SortItemList();

    //EnumBool();
    return a.exec();
}
