#ifndef EQUIPO_MANTENIMIENTO_H
#define EQUIPO_MANTENIMIENTO_H

#include "operario.h"
#include <vector>

class equipo_mantenimiento : public operario {
    friend ostream &operator<<(ostream &, const equipo_mantenimiento &); // Mostrar el vector de operarios

public:
    //Métodos generales
    equipo_mantenimiento(int = 3); //Constructor, recibe como parámetro la cantidad de operarios del equipo
    equipo_mantenimiento(const equipo_mantenimiento &); //Constructor de copia
    virtual ~equipo_mantenimiento(); //Destructor

    //Métodos específicos
    void set_operarios(); //Guardar operarios

    string get_nombre() const; //Recibir nombre del equipo
    void set_nombre_equipo(string); // Guardar nombre del equipo

    void set_integrantes(int); //Guardar cantidad de integrantes
    int get_integrantes() const; //Recibir integrantes

    void actualizar_operario(); //Actualiza la información de un operario

    void agregar_operario(const operario&);
    //Sobrecargas
    operario &operator[](int) const; //Sobrecarga de corchetes para simplificar el código

protected:
    vector <operario> equipo;
    string nombre_equipo;
    int integrantes;
};


#endif // EQUIPO_MANTENIMIENTO_H
