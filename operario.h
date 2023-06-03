#ifndef OPERARIO_H
#define OPERARIO_H

#include "fecha.h"

class operario {
    //Sobrecarga de entrada y salida
    friend ostream &operator<<(ostream &, const operario &);
    friend istream &operator>>(istream &, operario &);

public:
    //Métodos generales
    operario(); //Constructor
    operario(const operario &); //Constructor de copia
    virtual ~operario(); //Destructor

    //Métodos específicos
    void set_nombre(string); //Establecer nombre
    string get_nombre(); //Recibir nombre

    void set_id(string); //Establecer id
    string get_id(); //Recibir id

    void set_maquina(string); //Establecer máquina que opera
    string get_maquina(); //Recibir máquina que opera

    void set_ult_trabajo(fecha); //Establecer última fecha de trabajo
    fecha get_ult_trabajo(); //Recibir última fecha de trabajo

    void editaroperador();

    const operario &operator=(const operario &);

protected:
    string nombre; // Puede ser más de una palabra
    string id; // Una palabra
    fecha ult_trabajo;
    string maquina; // Es la placa de la maquina, una palabra
};


#endif // OPERARIO_H
