#include "computadora.h"

Computadora::Computadora(QObject *parent) : QObject(parent),
                                            hostInfo( new QHostInfo ),
                                            gateway( new QHostAddress("127.0.0.1") )
{

}

QString Computadora::getGateway() const
{
    return gateway->toString();
}

void Computadora::setGateway(const QString &value)
{
    gateway->setAddress( value );
}

QString Computadora::getHostName() const
{
    return hostInfo->hostName();
}

void Computadora::setHostName(const QString &value)
{
    hostInfo->setHostName( value );
}

QString Computadora::getIP() const
{
    QList< QHostAddress > list = hostInfo->addresses();
    if ( list.size() > 0 )  {
        return list.at(0).toString();
    }
    return QString( "127.0.0.1" );
}

void Computadora::setIP(const QString &value)
{
    QList< QHostAddress > list;
    QHostAddress ip( value );
    list << ip;

    hostInfo->setAddresses( list );
}
