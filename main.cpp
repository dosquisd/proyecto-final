#include "empresa.h"

// Lo que se hace en el main, es unicamente para probar que todo funcione:
// En concreto, se están probando el get, el set y la funcion de agregar un elemento a un seleccionado vector
// Dicha prueba, incluye el uso que se le dio a la funcion std::copy();

// Prueba realizada a los operarios: Exitosa. Tutto bene
// Prueba realizada a la maquinaria: Exitosa. Tutto bene

void imprimir_vector(const vector<operario>& vector) {
    for (int i = 0; i < vector.size(); i++)
        cout << vector[i] << endl;
}

void imprimir_vector(const vector<equipo_mantenimiento>& vector) {
    for(int i = 0; i < vector.size(); i++)
        cout << vector[i] << endl;
}

void imprimir_vector(const vector<maquinaria>& vector) {
    for (int i = 0; i < vector.size(); i++)
        cout << vector[i] << endl;
}


void prueba_operarios();
void prueba_equipos();
void prueba_maquinarias();

empresa a;
int main() {
    // prueba_operarios();

    prueba_equipos();

    // prueba_maquinarias();

    return 0;
}


void prueba_operarios() {
    vector <operario> nuevo(3);

    for (int i = 0; i < nuevo.size(); i++) {
        cout << "Operador " << i + 1 << endl;
        cin >> nuevo[i];

        cout << endl;
    }

    cout << "\nDatos operarios antes del cambio:\n";
    imprimir_vector(a.get_operadores());

    a.set_operadores(nuevo);

    cout << "\nDatos operario despues del cambio:\n";
    imprimir_vector(a.get_operadores());

    cout << "\n\n\nAgregar nuevo operario:\n";
    a.agregar_operario();

    cout << "\n\nOperadores despues del cambio:\n";
    imprimir_vector(a.get_operadores());
}

void prueba_equipos() {
    vector <equipo_mantenimiento> nuevo(3);
    int n;
    string nombre_equipo;

    // Llenar informacion del nuevo vector de equipo de mantenimiento
    for(int i = 0; i < nuevo.size(); i++) {
        operario operador_temp;
        cout << "Equipo " << i + 1 << endl;

        cout << "No. Integrantes: ";
        cin >> n;
        nuevo[i].set_integrantes(n);

        cout << "Nombre equipo: ";
        getline(cin, nombre_equipo);

        nuevo[i].set_nombre(nombre_equipo);

        for(int j = 0; j < n; j++) {
            cout << "Operador " << j + 1 << endl;

            cin >> operador_temp;
            nuevo[i].agregar_operario(operador_temp);

            cout << endl;
        }
    }

    cout << "\n\nDatos de equipos de mantenimiento antes del cambio:\n";
    imprimir_vector(nuevo);

    a.set_equipos(nuevo);

    cout << "\n\nDatos de equipos de mantenimiento despues del cambio\n";
    imprimir_vector(a.get_equipos());

    cout << "\n\n\nAgregar nuevo equipo:\n";
    a.agregar_equipo();

    cout << "\n\nEquipos de mantenimiento despues del cambio\n";
    imprimir_vector(a.get_equipos());
}

void prueba_maquinarias() {
    vector<maquinaria> nuevo(3);

    for(int i = 0; i < nuevo.size(); i++) {
        cout << "Maquinaria " << i + 1 << endl;

        cin >> nuevo[i];
        cout << endl;
    }

    cout << "\n\nDatos maquinaria antes del cambio:\n";
    imprimir_vector(a.get_maquinarias());

    a.set_maquinarias(nuevo);
    cout << "\nDatos maquinaria despues del cambio:\n";
    imprimir_vector(nuevo);

    cout << "\n\n\nAgregar nueva maquinaria:\n";
    a.agregar_maquinaria();

    cout << "\n\nMaquinarias despues del cambio:\n";
    imprimir_vector(a.get_maquinarias());
}