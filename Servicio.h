#ifndef SERVICIO_H
#define SERVICIO_H

#include "ListaPacientes.h"
#include <string>

using namespace std;

struct Servicio {
    string nombre;
    ListaPacientes* pacientes;
    Servicio* siguiente;

    Servicio(const string& nombre);
    ~Servicio();
};

#endif
