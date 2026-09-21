#ifndef LISTA_PACIENTES_H
#define LISTA_PACIENTES_H

#include "NodoPaciente.h"

class ListaPacientes {
private:
    NodoPaciente* cabeza;
    int cantidad;

public:
    ListaPacientes();
    ~ListaPacientes();

    void agregar(Paciente* p);
    bool existeId(const string& id) const;
    int getCantidad() const;
    void mostrar() const;
};

#endif
