#ifndef TABLA_H
#define TABLA_H

#include <QObject>
#include <QVector>

class Tabla : public QObject
{
    Q_OBJECT
public:
    explicit Tabla(QObject *parent = 0);

    void agregarRuta(QStringList ruta);

private:
    QVector< QStringList > tabla;

signals:

public slots:
};

#endif // TABLA_H
