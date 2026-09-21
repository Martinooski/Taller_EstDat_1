#ifndef COLA_H
#define COLA_H

#include "NodoPaciente.h"

class Cola {
private:
    NodoPaciente* frente;
    NodoPaciente* final;
    int cantidad;

public:
    Cola();
    ~Cola();

    void encolar(Paciente* p);
    Paciente* desencolar();
    bool estaVacia() const;
    int getCantidad() const;
    bool existeId(const string& id) const;
    void mostrar() const;
};

#endif
