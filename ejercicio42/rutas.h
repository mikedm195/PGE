#ifndef RUTAS_H
#define RUTAS_H

#include <QDebug>
#include <QList>
#include <QStringList>


class Rutas
{
public:
    QList<QStringList> genera1(){
        QList<QStringList> res;
        QStringList a;
        a << "genara1" << "a" << "b";
        QStringList b;
        b << "c" << "d" << "e";
        res.append(a);
        res.append(b);
        return res;
    }
    QList<QStringList> genera2(){
        QList<QStringList> res;
        QStringList a;
        a << "genara2";
        res.append(a);
        return res;
    }
    QList<QStringList> genera3(){
        QList<QStringList> res;
        QStringList a;
        a << "genara3";
        res.append(a);
        return res;
    }


    Rutas();
};

#endif // RUTAS_H
