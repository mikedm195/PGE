#include <QCoreApplication>
#include <QDebug>
#include "listado.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Listado<int> l(5);
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(5);
    qDebug() << "Listado 1:";
    for(int i = 0;i<l.length();i++)
        qDebug() << l.get(i);
    Listado<int> l2(3);
    l2.add(10);
    l2.add(11);
    l2.add(12);
    qDebug() << "Listado 2:";
    for(int i = 0;i<l2.length();i++)
        qDebug() << l2.get(i);
    Listado<int> l3 = l + l2;
    qDebug() << "Listado1 + Listado2:";
    for(int i = 0;i<l3.length();i++)
        qDebug() << l3.get(i) << " ";
    return a.exec();
}
