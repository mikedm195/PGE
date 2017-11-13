#include "router.h"

Router::Router(QObject *parent) : QObject(parent)
{

}

QString Router::getHostName() const
{
    return hostInfo.hostName();
}

void Router::setHostName(const QString &value)
{
    hostInfo.setHostName( value );
}

/**
 * @brief Router::setIPs Setea las IP de las dos unicas placas de red que tiene el router
 * @param ipout Pensado para la IP de salida a internet o conexion entre routers
 * @param ipin Pensado para la IP que recibe las comunicaciones desde los host de usuarios
 */
void Router::setIPs(const QString &ipout, const QString &ipin)
{
    QList< QHostAddress > list;
    QHostAddress ip1( ipout );
    QHostAddress ip2( ipin );
    list << ip1 << ip2;

    hostInfo.setAddresses( list );
}

QString Router::getIPout() const
{
    QList< QHostAddress > list = hostInfo.addresses();
    if ( list.size() > 0 )  {
        return list.at(0).toString();
    }
    return QString( "127.0.0.1" );
}

QString Router::getIPin() const
{
    QList< QHostAddress > list = hostInfo.addresses();
    if ( list.size() > 1 )  {
        return list.at(1).toString();
    }
    return QString( "127.0.0.1" );
}

void Router::setTabla(QList<QStringList> (Rutas::*pf)())
{
    qDebug() << (rutas.*pf)();
}
