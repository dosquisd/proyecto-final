#ifndef MAQUINARIA_H
#define MAQUINARIA_H

#include "equipo_mantenimiento.h"
#include "fecha.h"
using namespace std;

class maquinaria {
    friend ostream &operator << (ostream &, const maquinaria &);
    friend istream &operator >> (istream &, maquinaria &);

public:
    //métodos generales
    maquinaria(string = ""); //constructor
    maquinaria(const maquinaria &); //Constructor de copia
    virtual ~maquinaria(); //Destructor

    //Métodos específicos

    void set_placa(string); //Establecer placa de la maquina
    string get_placa(); //Establecer placa de la maquina

    void set_utilidad(string); //Establecer utilidad de la maquina
    string get_utilidad(); //Obtener utilidad de la maquina

    void set_idoperador(operario &); //Establecer id de operador, recibe directamente un operador para asegurar que este existe dentro del sistema
    string get_idoperador(); //Obtener id de operador.

    void set_nombre_equipo(equipo_mantenimiento &); //Establecer nombre del equipo de mantenimiento asignado, recibe directamente un equipo de mantenimiento para asegurar que este existen en el sistema
    string get_nombre_equipo(); //Obtener nombre del equipo de mantenimiento asignado

protected:
    // Atributos de la maquinaria
    string placa;
    string utilidad;
    string estado; //Bajo revisión de utilidad, nada de momento pero revísarlo luego*
    fecha ult_mantenimiento;
    fecha prox_mantenimiento;

    // Atributos de los operarios (incluyendo la clase equipo de mantenimiento)
    string id_operador;
    string nombre_equipo;
};


#endif // MAQUINARIA_H