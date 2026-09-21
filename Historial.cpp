#include "Historial.h"
#include <iostream>

Historial::Historial() : tope(nullptr), cantidad(0) {}

Historial::~Historial() {
    while (tope != nullptr) {
        NodoAtencion* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }
}

void Historial::agregarAtencion(const Atencion& a) {
    NodoAtencion* nuevo = new NodoAtencion(a);
    nuevo->siguiente = tope;
    tope = nuevo;
    cantidad++;
}

bool Historial::estaVacio() const {
    return tope == nullptr;
}

void Historial::mostrar() const {
    if (tope == nullptr) {
        cout << "Aun no se registran atenciones." << endl;
        return;
    }

    NodoAtencion* actual = tope;
    while (actual != nullptr) {
        cout << "Nombre: " << actual->atencion.nombre
             << " | Edad: " << actual->atencion.edad
             << " | Servicio: " << actual->atencion.servicio << endl;
        actual = actual->siguiente;
    }
}
