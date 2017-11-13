#ifndef ARCHIVADOR_H
#define ARCHIVADOR_H

#include <QFile>
#include <QTextStream>

class Archivador  {
private:
        static QFile *file;

public:
        static bool abrir(QString ruta){
            file->setFileName(ruta);

            if (!file->exists())  {
                    return false;
            }

            return file->open(QIODevice::Append | QIODevice::Text);
        }

        static bool almacenar(QString texto){
            if (!file->isOpen())
                    return false;

            QTextStream salida(file);
            salida << texto;

            return true;
        }
};

QFile * Archivador::file = new QFile("./defecto.txt");

#endif // ARCHIVADOR_H
