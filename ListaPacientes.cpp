#include "ListaPacientes.h"
#include <iostream>

ListaPacientes::ListaPacientes() : cabeza(nullptr), cantidad(0) {}

ListaPacientes::~ListaPacientes() {
    NodoPaciente* actual = cabeza;
    while (actual != nullptr) {
        NodoPaciente* temp = actual;
        actual = actual->siguiente;
        delete temp->paciente;
        delete temp;
    }
}

void ListaPacientes::agregar(Paciente* p) {
    NodoPaciente* nuevo = new NodoPaciente(p);

    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        NodoPaciente* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    cantidad++;
}

bool ListaPacientes::existeId(const string& id) const {
    NodoPaciente* actual = cabeza;
    while (actual != nullptr) {
        if (actual->paciente->getId() == id) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

int ListaPacientes::getCantidad() const {
    return cantidad;
}

void ListaPacientes::mostrar() const {
    if (cabeza == nullptr) {
        cout << "  (sin pacientes)" << endl;
        return;
    }

    NodoPaciente* actual = cabeza;
    while (actual != nullptr) {
        cout << "  ";
        actual->paciente->mostrar();
        cout << endl;
        actual = actual->siguiente;
    }
}
