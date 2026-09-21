#ifndef NODO_PACIENTE_H
#define NODO_PACIENTE_H

#include "Paciente.h"

struct NodoPaciente {
    Paciente* paciente;
    NodoPaciente* siguiente;

    NodoPaciente(Paciente* p) : paciente(p), siguiente(nullptr) {}
};

#endif
