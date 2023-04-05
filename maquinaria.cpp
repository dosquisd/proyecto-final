#include "maquinaria.h"

maquinaria::maquinaria() = default;

maquinaria::maquinaria(const maquinaria &copia) {
    placa = copia.placa;
    utilidad = copia.utilidad;
    estado = copia.estado;
    ult_mantenimiento = copia.ult_mantenimiento;
    prox_mantenimiento = copia.prox_mantenimiento;
    id_operador = copia.id_operador;
    nombre_equipo = copia.nombre_equipo;
}

maquinaria::~maquinaria() = default;

void maquinaria::set_placa(string pl) {
    placa = pl;
}

string maquinaria::get_placa() {
    return placa;
}

void maquinaria::set_utilidad(string uti) {
    utilidad = uti;
}

void maquinaria::set_idoperador(operario &a) {
    id_operador = a.get_id();
}

string maquinaria::get_idoperador() {
    return id_operador;
}

void maquinaria::set_nombre_equipo(equipo_mantenimiento &a) {
    nombre_equipo = a.get_nombre();
}

string maquinaria::get_nombre_equipo() {
    return nombre_equipo;
}

ostream &operator<<(ostream &out, const maquinaria& a) {
    out << "Nombre del equipo: " << a.nombre_equipo << endl;
    out << "ID del operador: " << a.id_operador << endl;

    out << "\nDatos acerca de la maquinaria:\n";
    out << "Placa: " << a.placa << endl;
    out << "Utilidad: " << a.utilidad << endl;
    out << "Estado: " << a.estado << endl;
    out << "Última fecha de mantenimiento: " << a.ult_mantenimiento << endl;
    out << "Próxima fecha de mantenimiento: " << a.prox_mantenimiento << endl;

    return out;
}

istream &operator>>(istream &in, maquinaria& a) {
    cout << "Nombre del equipo: ";
    getline(in, a.nombre_equipo);
    cout << "ID del operador: ";
    getline(in, a.id_operador);

    cout << "Placa de la maquinaria: ";
    getline(in, a.placa);
    cout << "Utilidad de la maquinaria: ";
    getline(in, a.utilidad);
    cout << "Estado de la maquinaria: ";
    getline(in, a.estado);

    cout << "Última fecha de mantinimiento: ";
    in >> a.ult_mantenimiento;
    cout << "Próxima fecha de mantenimiento: ";
    in >> a.prox_mantenimiento;

    return in;
}