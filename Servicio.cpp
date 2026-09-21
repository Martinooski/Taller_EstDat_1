#include "Servicio.h"

Servicio::Servicio(const string& nombre) : nombre(nombre), siguiente(nullptr) {
    pacientes = new ListaPacientes();
}

Servicio::~Servicio() {
    delete pacientes;
}
