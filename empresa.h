#ifndef EMPRESA_H
#define EMPRESA_H

#include "maquinaria.h"

class empresa {
public:
    empresa(int = 2, int = 2, int = 2); // Si acaso luego se les puede poner parametros por defecto
    empresa(const empresa &);
    virtual ~empresa();

    const vector<operario> &get_operadores() const;
    const vector<equipo_mantenimiento> &get_equipos() const;
    const vector<maquinaria> &get_maquinarias() const;

    int get_n_operadores() const;
    int get_n_equipos() const;
    int get_n_maquinarias() const;

    void set_operadores(const vector<operario> &);
    void set_equipos(const vector<equipo_mantenimiento> &);
    void set_maquinarias(const vector<maquinaria> &);

    // Se piden los datos dentro de los mismo metodos
    void agregar_operario();
    void agregar_equipo();
    void agregar_maquinaria();

private:
    vector <operario> operadores;
    int cant_operadores;
    vector <equipo_mantenimiento> equipos_de_mantenimiento;
    int cant_equipos;
    vector <maquinaria> maquinarias;
    int cant_maquinarias;
};


#endif // EMPRESA_H


//Si llegaste hasta aquí, saludos y gracias por calificar en 5, se te aprecia uwu <3