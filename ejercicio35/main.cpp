#include <QCoreApplication>
#include <QVector>
#include <QDebug>
#include <iostream>
#include <QString>

#include "ordenador.h"
#include "listadeenteros.h"
#include "persona.h"
#include <time.h>
#include "archivador.h"

void (*f) (int*,int);

int main(int argc, char *argv[])
{    
    QCoreApplication a(argc, argv);

    qsrand(time(NULL));

    ListaDeEnteros<int> l;


    void (Ordenador<int>::*puntero[3])(int*, int);
    puntero[0] = &Ordenador<int>::burbuja;
    puntero[1] = &Ordenador<int>::insercion;
    puntero[2] = &Ordenador<int>::seleccion;

    if(!Archivador::abrir("./tiempos.txt"))
        qDebug() << "Crear antes el archivo tiempos.txt";

    for(int i = 0;i<50000;i++)
        l.append(qrand() % 100000);
    clock_t begin = clock();
    l.ordenar( puntero[0] );
    clock_t end = clock();
    double time_spent1 = ((double) (end - begin) / CLOCKS_PER_SEC);
    qDebug() << time_spent1 << "s" << '\n';
    Archivador::almacenar("Burbuja: " + QString::number(time_spent1) + "s\n");

    for(int i = 0;i<50000;i++)
        l.append(qrand() % 100000);
    begin = clock();
    l.ordenar( puntero[1] );
    end = clock();
    time_spent1 = ((double) (end - begin) / CLOCKS_PER_SEC);
    qDebug() << time_spent1 << "s" << '\n';
    Archivador::almacenar("Insercion " + QString::number(time_spent1) + "s\n");

    for(int i = 0;i<50000;i++)
        l.append(qrand() % 100000);
    begin = clock();
    l.ordenar( puntero[2] );
    end = clock();
    time_spent1 = ((double) (end - begin) / CLOCKS_PER_SEC);
    qDebug() << time_spent1 << "s" << '\n';
    Archivador::almacenar("Seleccion: " + QString::number(time_spent1) + "s\n");
    return a.exec();
}
