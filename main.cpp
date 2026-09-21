#include <iostream>
#include "Hospital.h"

using namespace std;

int main() {
    Hospital hospital;

    try {
        hospital.cargarPacientes("pacientes.txt");
    } catch (const exception& e) {
        cout << "Error al cargar pacientes: " << e.what() << endl;
    }

    int opcion = 0;
    do {
        cout << "\n=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamentos" << endl;
        cout << "3. Ver pacientes en espera" << endl;
        cout << "4. Revisar historial de atencion" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccionar opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opcion invalida." << endl;
            continue;
        }

        switch (opcion) {
            case 1: {
                hospital.mostrarCola();
                cout << "Indique la cantidad de pacientes a atender: ";
                int cantidad;
                cin >> cantidad;
                if (cin.fail() || cantidad <= 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Cantidad invalida." << endl;
                } else {
                    cout << "\n=== ATENDIENDO PACIENTES ===" << endl;
                    hospital.atenderPacientes(cantidad);
                }
                break;
            }
            case 2: {
                hospital.mostrarServicios();
                cout << "Seleccionar departamento (0 para volver): ";
                int indice;
                cin >> indice;
                if (!cin.fail() && indice != 0) {
                    hospital.mostrarServicio(indice);
                }
                break;
            }
            case 3:
                hospital.mostrarCola();
                break;
            case 4:
                hospital.mostrarHistorial();
                break;
            case 5:
                cout << "Hasta luego ." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}
