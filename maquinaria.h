#ifndef MAQUINARIA_H
#define MAQUINARIA_H

#include "equipo_mantenimiento.h"
#include "fecha.h"
using namespace std;

class maquinaria {
    friend ostream &operator<<(ostream &, const maquinaria &);
    friend istream &operator>>(istream &, maquinaria &);

public:
    //métodos generales
    maquinaria(string = ""); //constructor
    maquinaria(const maquinaria &); //Constructor de copia
    virtual ~maquinaria(); //Destructor

    //Métodos específicos
    void set_placa(string); //Establecer placa de la maquina
    string get_placa(); // Obtener placa de la maquina

    void set_utilidad(string); //Establecer utilidad de la maquina
    string get_utilidad(); //Obtener utilidad de la maquina

    void set_idoperador(operario &); //Establecer id de operador, recibe directamente un operador para asegurar que este existe dentro del sistema
    void set_idoperador(string); //Establecer id del operador, recibe directamente la cadena
    string get_idoperador(); //Obtener id de operador.

    void set_nombre_equipo(equipo_mantenimiento &); //Establecer nombre del equipo de mantenimiento asignado, recibe directamente un equipo de mantenimiento para asegurar que este existen en el sistema
    void set_nombre_equipo(string); //Establecer nombre del equipo de mantenimiento asignado, recibe directamente una cadena
    string get_nombre_equipo(); //Obtener nombre del equipo de mantenimiento asignado

    void set_estado(); //Establecer estado de la maquinaria, dentro del mismo metodo se pide el estado
    void set_estado(string); //Establecer estado de la maquinaria, directamente recibe la cadena con el estado asumiendo que previamente fue válidada
    string get_estado(); //Obtener estado de la maquinaria

    void set_ult_mantenimiento(fecha); //Establecer la última fecha de mantenimiento, recibe directamente la fecha de la última vez que se le hizo mantenimiento
    fecha get_ult_mantenimiento(); //Obtener la última de fecha en la que se le hizo mantenimiento a la maquinaria

    void set_prox_mantenimiento(fecha); //Establecer la próxima fecha de mantenimiento, recible directamente al fecha con la próxima fecha que se le debe hacer mantenimiento
    fecha get_prox_mantenimiento(); //Obtener la fecha próxima en la que se le hará mantenimiento a la maquinaria

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