#include "empresa.h"

empresa::empresa(int n_op, int n_equipos, int n_maquinas) {
    cant_operadores = n_op;
    cant_equipos = n_equipos;
    cant_maquinarias = n_maquinas;

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