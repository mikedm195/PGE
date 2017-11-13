#include "logger.h"

#include <QDebug>

Logger * Logger::instancia = NULL;

Logger::Logger()
{

}

Logger * Logger::getInstancia(){
    if( instancia == NULL )
    {
        instancia = new Logger();
    }
    return instancia;
}

void Logger::registrarEvento(QString s)
{
    qDebug() << s;
}
