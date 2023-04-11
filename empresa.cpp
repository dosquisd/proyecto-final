#include "empresa.h"

empresa::empresa(int n_op, int n_equipos, int n_maquinas) {
    cant_operadores = (n_op > 2) ? n_op : 2;
    cant_equipos = (n_equipos > 2) ? n_equipos : 2;
    cant_maquinarias = (n_maquinas > 2) ? n_maquinas : 2;

    // Cambiar el tamaño de los vectores al nuevo ingresado
    operadores.resize(n_op);
    equipos_de_mantenimiento.resize(n_equipos);
    maquinarias.resize(n_maquinas);
}

empresa::empresa(const empresa &copia) {
    // Redifinir el tamaño de las vectores
    cant_operadores = copia.cant_operadores;
    cant_equipos = copia.cant_equipos;
    cant_maquinarias = copia.cant_maquinarias;

    operadores.resize(cant_operadores);
    equipos_de_mantenimiento.resize(cant_equipos);
    maquinarias.resize(cant_maquinarias);

    // Copiar los elementos de los vectores del otro objeto
    copy(copia.operadores.begin(), copia.operadores.end(), operadores.begin());
    copy(copia.equipos_de_mantenimiento.begin(), copia.equipos_de_mantenimiento.end(), equipos_de_mantenimiento.begin());
    copy(copia.maquinarias.begin(), copia.maquinarias.end(), maquinarias.begin());
}

empresa::~empresa() {
    // Realmente desconozco si esto es necesario, pero por si las moscas aquí queda
    operadores.clear();
    equipos_de_mantenimiento.clear();
    maquinarias.clear();
}

const vector<operario> &empresa::get_operadores() const {
    return operadores;
}

const vector<equipo_mantenimiento> &empresa::get_equipos() const {
    return equipos_de_mantenimiento;
}

const vector<maquinaria> &empresa::get_maquinarias() const {
    return maquinarias;
}

void empresa::set_operadores(const vector<operario>& a) {
    operadores.resize(a.size());

    copy(a.begin(), a.end(), operadores.begin());
}

void empresa::set_equipos(const vector<equipo_mantenimiento> & a) {
    equipos_de_mantenimiento.resize(a.size());

    copy(a.begin(), a.end(), equipos_de_mantenimiento.begin());
}

void empresa::set_maquinarias(const vector<maquinaria> & a) {
    maquinarias.resize(a.size());

    copy(a.begin(), a.end(), maquinarias.begin());
}

void empresa::agregar_operario() {
    operario operador_temp;

    cin >> operador_temp;

    operadores.push_back(operador_temp);
}

void empresa::agregar_equipo() {
    string nombre_equipo;
    int n_integrantes;
    operario operador_temp;
    equipo_mantenimiento equipo_temp;

    cout << "Nombre equipo: ";
    getline(cin, nombre_equipo);

    cout << "No. Integrantes: ";
    cin >> n_integrantes;

    for (int i = 0; i < n_integrantes; i++) {
        cout << "Operario " << i + 1 << endl;

        cin >> operador_temp;
        equipo_temp.agregar_operario(operador_temp);

        cout << endl;
    }

    equipos_de_mantenimiento.push_back(equipo_temp);
}

void empresa::agregar_maquinaria() {
    maquinaria maquinaria_temp;

    cin >> maquinaria_temp;

    maquinarias.push_back(maquinaria_temp);
}