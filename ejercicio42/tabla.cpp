#include "tabla.h"

Tabla::Tabla(QObject *parent) : QObject(parent)
{

}

/**
 * @brief Tabla::agregarRuta Agraga una nueva ruta a la tabla de ruteo de esta router
 * @param ruta El QStringList debe tener 3 QString / Red destino - mascara - gateway
 * Por ejemplo:
 *              10.0.0.0    255.0.0.0       192.168.0.2
 *              192.168.0.0 255.255.255.0   10.0.0.1
 *              0.0.0.0     0.0.0.0         192.168.0.1
 */
void Tabla::agregarRuta(QStringList ruta)
{
    tabla << ruta;
}

