#ifndef ROUTER_H
#define ROUTER_H

#include <QObject>
#include <QHostInfo>
#include <QHostAddress>
#include <QList>
#include <QStringList>

#include "tabla.h"
#include "rutas.h"

class Router : public QObject
{
    Q_OBJECT
public:
    explicit Router(QObject *parent = 0);

    QString getHostName() const;
    void setHostName(const QString &value);

    void setIPs(const QString &ipout, const QString &ipin);

    QString getIPout() const;
    QString getIPin() const;

    void setTabla(QList<QStringList>  (Rutas::*pf)());

private:
    QHostInfo hostInfo;
    Tabla tabla;
    Rutas rutas;

signals:

public slots:
};

#endif // ROUTER_H
