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