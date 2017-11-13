#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <QObject>
#include <QHostInfo>
#include <QHostAddress>

class Computadora : public QObject
{
    Q_OBJECT
public:
    explicit Computadora(QObject *parent = 0);

    QString getGateway() const;
    void setGateway(const QString &value);

    QString getHostName() const;
    void setHostName(const QString &value);

    QString getIP() const;
    void setIP(const QString &value);

private:
    QHostInfo * hostInfo;
    QHostAddress * gateway;

signals:

public slots:
};

#endif // COMPUTADORA_H
