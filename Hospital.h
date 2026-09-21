#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Servicio.h"
#include "Cola.h"
#include "Historial.h"
#include <string>

using namespace std;

class Hospital {
private:
    Servicio* listaServicios;
    Cola colaEspera;
    Historial historial;

    Servicio* buscarServicio(const string& nombre) const;
    bool esServicioValido(const string& nombre) const;
    bool existeIdEnHospital(const string& id) const;
    bool parsearLinea(const string& linea, string& id, string& nombre,
                       int& edad, string& servicio) const;

public:
    Hospital();
    ~Hospital();

    void cargarPacientes(const string& rutaArchivo);
    void atenderPacientes(int cantidad);
    void mostrarCola() const;
    void mostrarServicios() const;
    void mostrarServicio(int indice) const;
    void mostrarHistorial() const;
};

#endif
