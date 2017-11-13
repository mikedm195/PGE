#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QVector>

#include "login.h"
#include "formulario.h"

class Manager : public QObject
{
    Q_OBJECT

private:
    static Manager *instancia;
    explicit Manager( QObject * parent = 0 );

public:
    static Manager *getInstancia();
    ~Manager();

    void iniciar();   

private slots:
    void slot_ingreso( bool valido, QStringList usuario );
    void slot_agregar_usuario( QVector< QStringList > usuarios );

};

#endif // MANAGER_H
