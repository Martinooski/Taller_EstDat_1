#include "Cola.h"
#include <iostream>

Cola::Cola() : frente(nullptr), final(nullptr), cantidad(0) {}

Cola::~Cola() {
    while (frente != nullptr) {
        NodoPaciente* temp = frente;
        frente = frente->siguiente;
        delete temp->paciente;
        delete temp;
    }
}

void Cola::encolar(Paciente* p) {
    NodoPaciente* nuevo = new NodoPaciente(p);

    if (final == nullptr) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
    cantidad++;
}

Paciente* Cola::desencolar() {
    if (frente == nullptr) {
        return nullptr;
    }

    NodoPaciente* temp = frente;
    Paciente* p = temp->paciente;

    frente = frente->siguiente;
    if (frente == nullptr) {
        final = nullptr;
    }

    delete temp;
    cantidad--;
    return p;
}

bool Cola::estaVacia() const {
    return frente == nullptr;
}

int Cola::getCantidad() const {
    return cantidad;
}

bool Cola::existeId(const string& id) const {
    NodoPaciente* actual = frente;
    while (actual != nullptr) {
        if (actual->paciente->getId() == id) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void Cola::mostrar() const {
    if (frente == nullptr) {
        cout << "No hay pacientes en espera." << endl;
        return;
    }

    NodoPaciente* actual = frente;
    int contador = 1;
    while (actual != nullptr) {
        cout << contador << ". ";
        actual->paciente->mostrar();
        cout << endl;
        actual = actual->siguiente;
        contador++;
    }
}
