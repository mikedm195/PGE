#ifndef PERSONA_H
#define PERSONA_H

class Persona
{
public:
    QString nombre;
    int edad;
    Persona(){

    }

    Persona(QString nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    }
    bool operator <(Persona otro){
        return this->edad < otro.edad;
    }
    bool operator >(Persona otro){
        return this->edad > otro.edad;
    }

};

#endif // PERSONA_H
