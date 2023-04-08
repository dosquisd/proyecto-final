#ifndef EMPRESA_H
#define EMPRESA_H

#include "maquinaria.h"

class empresa {
public:
    empresa(int = 2, int = 2, int = 2); // Si acaso luego se les puede poner parametros por defecto
    empresa(const empresa &);
    virtual ~empresa();

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