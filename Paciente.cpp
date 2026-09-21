#include "Paciente.h"
#include <iostream>

Paciente::Paciente(const string& id, const string& nombre, int edad, const string& servicio)
    : Persona(nombre, edad), id(id), servicio(servicio) {}

string Paciente::getId() const {
    return id;
}

string Paciente::getServicio() const {
    return servicio;
}

void Paciente::mostrar() const {
    cout << id << " - " << nombre << " (" << edad << ") -> " << servicio;
}
