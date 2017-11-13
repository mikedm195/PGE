#ifndef LOGGER_H
#define LOGGER_H

#include <QString>

class Logger
{
private:
    static Logger *instancia;
    Logger();

public:
    static Logger *getInstancia();
    ~Logger();

    void registrarEvento(QString s);

};

#endif // LOGGER_H
