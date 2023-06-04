#include "maquinaria.h"

maquinaria::maquinaria(string uti) {
    placa = "0000";
    utilidad = uti;
    estado = "Óptimo";
    id_operador = "0000";
    nombre_equipo = "Sin equipo";
}

maquinaria::maquinaria(const maquinaria &copia) {
    placa = copia.placa;
    utilidad = copia.utilidad;
    estado = copia.estado;
    ult_mantenimiento = copia.ult_mantenimiento;
    prox_mantenimiento = copia.prox_mantenimiento;
    id_operador = copia.id_operador;
    nombre_equipo = copia.nombre_equipo;
}

maquinaria::~maquinaria() {}

void maquinaria::set_placa(string pl) {
    placa = pl;
}

string maquinaria::get_placa() {
    return placa;
}

void maquinaria::set_utilidad(string uti) {
    utilidad = uti;
}

string maquinaria::get_utilidad() {
    return utilidad;
}

void maquinaria::set_idoperador(operario &a) {
    id_operador = a.get_id();
}

void maquinaria::set_idoperador(string id) {
    id_operador = id;
}

string maquinaria::get_idoperador() {
    return id_operador;
}

void maquinaria::set_nombre_equipo(equipo_mantenimiento &a) {
    nombre_equipo = a.get_nombre();
}

void maquinaria::set_nombre_equipo(string nombre) {
    nombre_equipo = nombre;
}

string maquinaria::get_nombre_equipo() {
    return nombre_equipo;
}

void maquinaria::set_estado() {
    int x = 0;
    do {
        cout << "1 - Óptimo." << endl;
        cout << "2 - Medio." << endl;
        cout << "3 - Dañado." << endl;
        cout << "Por favor, ingrese el número relacionado con el estado de la máquina: ";
        cin >> x;
        switch (x) {
            case 1:
                estado = "Óptimo";
                break;
            case 2:
                estado = "Medio";
                break;
            case 3:
                estado = "Dañado";
                break;
            default:
                cout<< "El número ingresado no corresponde a ninguno de los estados posible, por favor ingréselo nuevamente"<< endl;
                x = 0;
                break;
        }
    } while (x == 0);
}

void maquinaria::set_estado(string a) {
    estado = a;
}

string maquinaria::get_estado() {
    return estado;
}

void maquinaria::set_ult_mantenimiento(fecha a) {
    ult_mantenimiento = a;
}

fecha maquinaria::get_ult_mantenimiento() {
    return ult_mantenimiento;
}

void maquinaria::set_prox_mantenimiento(fecha a) {
    prox_mantenimiento = a;
}

fecha maquinaria::get_prox_mantenimiento() {
    return prox_mantenimiento;
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
    cout << "Placa de la maquinaria: ";
    in >> a.placa;
    cout << "Última fecha de mantenimiento: ";
    in >> a.ult_mantenimiento;

    do {
        cout << "Próxima fecha de mantenimiento: ";
        in >> a.prox_mantenimiento;
        if (a.prox_mantenimiento < a.ult_mantenimiento)
            cout << "No es posible que el próximo mantenimiento sea previo al último realizado. Inténtelo nuevamente" << endl;

    } while(a.prox_mantenimiento < a.ult_mantenimiento);

    a.set_estado();

    return in;
}