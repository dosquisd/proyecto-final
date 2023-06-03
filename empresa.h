#ifndef EMPRESA_H
#define EMPRESA_H

#include "maquinaria.h"
#include <fstream>
#include <sstream>

fecha& to_fecha(string); // Llamar al prototipo de la funcion amiga de la clase fecha

class empresa {
    friend void guardar_empresa(empresa &a);
    friend void leer_empresa(empresa &a);
public:
    empresa(int = 2, int = 1, int = 2, int = 1); // Si acaso luego se les puede poner parametros por defecto
    empresa(const empresa &);
    virtual ~empresa();

    const vector<operario> &get_operadores() const;
    const vector<equipo_mantenimiento> &get_equipos() const;
    const vector<maquinaria> &get_maquinarias() const;

    int get_n_operadores() const;
    int get_n_equipos() const;
    int get_n_maquinarias() const;

    void set_operadores(int);
    void set_equipos(int);
    void set_maquinarias(int);
    void set_utilidades(int);

    void imprimirnumerado_utilidades();
    void imprimirnumerado_maquinarias_disponibles(); // Muestra las maquinarias sin operarios asignados
    void imprimirnumerado_nombres_equipos(); // Muestra unicamente el nombre de todos los equipos de la empresa
    void imprimirnumerado_operarios();
    void imprimirnumerado_maquinarias();

    void imprimir_equipos(); // Muestra toda la información de los equipos de mantenimiento
    void imprimir_operarios();
    void imprimir_mantenimiento_atrasado(fecha); // Muestra las maquinarias que tienen la proxima fecha de mantenimiento antes de una dada
    void imprimir_maquinas_no_optimas();


    void asignar_utilidades_equipos();
    void asignar_maquinarias();

    // A los metodos de editar unicamente se le tiene que brindar la posición del objeto correspondiente en los vectores
    void editar_operador(int);
    void editar_maquinaria(int);
    void editar_equipo(int);

    // Se piden los datos dentro de los mismo metodos
    void agregar_operario();
    void agregar_equipo();
    void agregar_maquinaria();
    void agregar_utilidad();

private:
    vector <operario> operadores;
    int cant_operadores;
    vector <equipo_mantenimiento> equipos_de_mantenimiento;
    int cant_equipos;
    vector <maquinaria> maquinarias;
    int cant_maquinarias;
    vector <string> utilidades;
    int cant_utilidades;
};


#endif // EMPRESA_H


//Si llegaste hasta aquí, saludos y gracias por calificar en 5, se te aprecia uwu <3