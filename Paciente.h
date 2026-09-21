#ifndef PACIENTE_H
#define PACIENTE_H

#include "Persona.h"
#include <string>

using namespace std;


class Paciente : public Persona {
private:
    string id;
    string servicio;

public:
    Paciente(const string& id, const string& nombre, int edad, const string& servicio);

    string getId() const;
    string getServicio() const;

    void mostrar() const override;
};

#endif
