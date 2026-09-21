#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona(const string& nombre, int edad);
    virtual ~Persona() {}

    string getNombre() const;
    int getEdad() const;

    virtual void mostrar() const;
};

#endif
