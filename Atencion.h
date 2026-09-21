#ifndef ATENCION_H
#define ATENCION_H

#include <string>

using namespace std;

struct Atencion {
    string idPaciente;
    string nombre;
    int edad;
    string servicio;
};

struct NodoAtencion {
    Atencion atencion;
    NodoAtencion* siguiente;

    NodoAtencion(const Atencion& a) : atencion(a), siguiente(nullptr) {}
};

#endif
