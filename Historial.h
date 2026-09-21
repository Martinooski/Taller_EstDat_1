#ifndef HISTORIAL_H
#define HISTORIAL_H

#include "Atencion.h"

class Historial {
private:
    NodoAtencion* tope;
    int cantidad;

public:
    Historial();
    ~Historial();

    void agregarAtencion(const Atencion& a);
    bool estaVacio() const;
    void mostrar() const;
};

#endif
