#include "Hospital.h"
#include <iostream>
#include <fstream>

const int CANTIDAD_SERVICIOS = 8;
const string NOMBRES_SERVICIOS[CANTIDAD_SERVICIOS] = {
    "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
    "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
};

Hospital::Hospital() : listaServicios(nullptr) {
    // Se arma la lista enlazada principal con los 8 servicios fijos.
    Servicio* ultimo = nullptr;
    for (int i = 0; i < CANTIDAD_SERVICIOS; i++) {
        Servicio* nuevo = new Servicio(NOMBRES_SERVICIOS[i]);
        if (listaServicios == nullptr) {
            listaServicios = nuevo;
        } else {
            ultimo->siguiente = nuevo;
        }
        ultimo = nuevo;
    }
}

Hospital::~Hospital() {
    Servicio* actual = listaServicios;
    while (actual != nullptr) {
        Servicio* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

Servicio* Hospital::buscarServicio(const string& nombre) const {
    Servicio* actual = listaServicios;
    while (actual != nullptr) {
        if (actual->nombre == nombre) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

bool Hospital::esServicioValido(const string& nombre) const {
    return buscarServicio(nombre) != nullptr;
}

bool Hospital::existeIdEnHospital(const string& id) const {
    if (colaEspera.existeId(id)) {
        return true;
    }

    Servicio* actual = listaServicios;
    while (actual != nullptr) {
        if (actual->pacientes->existeId(id)) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

// Separa "ID;Nombre;Edad;Servicio" recorriendo el buffer con un
// puntero y avanzandolo caracter a caracter (aritmetica de punteros)
// en vez de usar stringstream o find de std::string.
bool Hospital::parsearLinea(const string& linea, string& id, string& nombre,
                             int& edad, string& servicio) const {
    const char* ptr = linea.c_str();
    string campos[4];
    int indiceCampo = 0;

    while (*ptr != '\0' && indiceCampo < 4) {
        const char* comienzoCampo = ptr;
        while (*ptr != '\0' && *ptr != ';') {
            ptr++;
        }
        campos[indiceCampo] = string(comienzoCampo, ptr - comienzoCampo);
        indiceCampo++;
        if (*ptr == ';') {
            ptr++;
        }
    }

    if (indiceCampo != 4 || campos[0].empty() || campos[1].empty() || campos[3].empty()) {
        return false;
    }

    try {
        edad = stoi(campos[2]);
    } catch (...) {
        return false;
    }

    id = campos[0];
    nombre = campos[1];
    servicio = campos[3];
    return true;
}

void Hospital::cargarPacientes(const string& rutaArchivo) {
    ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo '" + rutaArchivo + "'");
    }

    string linea;
    int numeroLinea = 0;
    while (getline(archivo, linea)) {
        numeroLinea++;
        if (linea.empty()) {
            continue;
        }

        string id, nombre, servicio;
        int edad;

        if (!parsearLinea(linea, id, nombre, edad, servicio)) {
            cout << "Linea " << numeroLinea << " invalida, se omite: " << linea << endl;
            continue;
        }

        if (!esServicioValido(servicio)) {
            cout << "Linea " << numeroLinea << ": servicio '" << servicio
                 << "' no existe, se omite paciente " << id << endl;
            continue;
        }

        if (existeIdEnHospital(id)) {
            cout << "Linea " << numeroLinea << ": paciente con id " << id
                 << " duplicado, se omite" << endl;
            continue;
        }

        Paciente* nuevoPaciente = new Paciente(id, nombre, edad, servicio);
        colaEspera.encolar(nuevoPaciente);
    }

    archivo.close();
}

void Hospital::atenderPacientes(int cantidad) {
    if (colaEspera.estaVacia()) {
        cout << "No hay pacientes en espera para atender." << endl;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        if (colaEspera.estaVacia()) {
            cout << "No quedan mas pacientes en espera." << endl;
            break;
        }

        Paciente* p = colaEspera.desencolar();

        cout << "\nID: " << p->getId() << endl;
        cout << "Nombre: " << p->getNombre() << endl;
        cout << "Edad: " << p->getEdad() << endl;
        cout << "Servicio: " << p->getServicio() << endl;

        Servicio* servicio = buscarServicio(p->getServicio());
        servicio->pacientes->agregar(p);
        cout << "Paciente enviado a " << servicio->nombre << "." << endl;

        Atencion a;
        a.idPaciente = p->getId();
        a.nombre = p->getNombre();
        a.edad = p->getEdad();
        a.servicio = p->getServicio();
        historial.agregarAtencion(a);
    }
}

void Hospital::mostrarCola() const {
    cout << "\n=== PACIENTES EN ESPERA (" << colaEspera.getCantidad() << ") ===" << endl;
    colaEspera.mostrar();
}

void Hospital::mostrarServicios() const {
    cout << "\n=== DEPARTAMENTOS/SERVICIOS ===" << endl;
    Servicio* actual = listaServicios;
    int contador = 1;
    while (actual != nullptr) {
        cout << contador << ". " << actual->nombre
             << " (" << actual->pacientes->getCantidad() << " pacientes)" << endl;
        actual = actual->siguiente;
        contador++;
    }
}

void Hospital::mostrarServicio(int indice) const {
    if (indice < 1 || indice > CANTIDAD_SERVICIOS) {
        cout << "Opcion de departamento invalida." << endl;
        return;
    }

    Servicio* actual = listaServicios;
    int contador = 1;
    while (contador < indice) {
        actual = actual->siguiente;
        contador++;
    }

    cout << "\n=== ESTADO " << actual->nombre << " ===" << endl;
    cout << "Pacientes en el departamento: " << actual->pacientes->getCantidad() << endl;
    actual->pacientes->mostrar();
}

void Hospital::mostrarHistorial() const {
    cout << "\n=== HISTORIAL DE ATENCIONES DEL HOSPITAL ===" << endl;
    historial.mostrar();
}
