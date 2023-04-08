#include "operario.h"

//Métodos generales

operario::operario() { //Constructor
    //inicializamos todas las variables que contiene la clase
    nombre = "0";
    id = "0";
    maquina="0";
    //No es necesario inicializar las variables de clase fecha, ya que estas tienen un valor predeterminado al ser creadas.

}

operario::operario(const operario &copia) { //constructor de copia
    nombre=copia.nombre;
    id=copia.id;
    maquina=copia.maquina;
    ult_trabajo=copia.ult_trabajo;
}
operario::~operario() {}  //Destructor

//Métodos específicos

void operario::set_id(string a) {//Establecer id del operario
    id=a;
}
string operario::get_id() { //Retornar id del operador
    return id;
}

void operario::set_maquina(string a) { //Establecer máquina del operador
    maquina=a;
}
string operario::get_maquina() { //Retornar maquina del operador
    return maquina;
}

void operario::set_nombre(string a) { //Establecer nombre del operador
    nombre=a;
}
string operario::get_nombre() { //Retornar nombre del operador
    return nombre;
}

void operario::set_utl_trabajo(fecha a) { //Establecer última fecha de trabajo
    ult_trabajo = a;
}
fecha operario::get_ult_trabajo() { //Retornar última fecha de trabajo
    return ult_trabajo;
}

//Sobrecargas de entrada y salida
ostream &operator << (ostream &cout, const operario &a){
    cout << "Nombre: "<< a.nombre << endl;
    cout << "ID: " << a.id << endl;
    cout << "Placa de máquina encargada: " << a.maquina << endl;
    cout << "Fecha de su último trabajo: " << a.ult_trabajo << endl;
    return cout;
}

istream &operator >> (istream &cin, operario &a){
    cout << "Por favor, ingrese el nombre del operador:  ";
    cin >>a.nombre;
    cout << "Por favor, ingrese el ID del operador:  ";
    cin >>a.id;
    cout << "Por favor, ingrese la placa de la máquina que opera:  ";
    cin >>a.maquina;
    cout << "Por favor, ingrese su última fecha de trabajo:\n";
    cin >> a.ult_trabajo;
}

//sobrecarga de otros operadores
operario operario::operator=(const operario &igual) {
    nombre=igual.nombre;
    id=igual.id;
    maquina=igual.maquina;
    ult_trabajo=igual.ult_trabajo;
}