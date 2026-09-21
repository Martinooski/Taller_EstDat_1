#include "Persona.h"
#include <iostream>

Persona::Persona(const string& nombre, int edad) : nombre(nombre), edad(edad) {}

string Persona::getNombre() const {
    return nombre;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::mostrar() const {
    cout << nombre << " (" << edad << ")";
}
