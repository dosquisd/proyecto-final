#include "operario.h"

//Métodos generales

operario::operario() { //Constructor
    //inicializamos todas las variables que contiene la clase
    nombre = "0";
    id = "0";
    maquina = "0";
    //No es necesario inicializar las variables de clase fecha, ya que estas tienen un valor predeterminado al ser creadas.
}

operario::operario(const operario &copia) { //constructor de copia
    nombre = copia.nombre;
    id = copia.id;
    maquina = copia.maquina;
    ult_trabajo = copia.ult_trabajo;
}
operario::~operario() {}  //Destructor

//Métodos específicos

void operario::set_id(string a) {//Establecer id del operario
    id = a;
}

string operario::get_id() { //Retornar id del operador
    return id;
}

void operario::set_maquina(string a) { //Establecer máquina del operador
    maquina = a;
}

string operario::get_maquina() { //Retornar maquina del operador
    return maquina;
}

void operario::set_nombre(string a) { //Establecer nombre del operador
    nombre = a;
}

string operario::get_nombre() { //Retornar nombre del operador
    return nombre;
}

void operario::set_ult_trabajo(fecha a) { //Establecer última fecha de trabajo
    ult_trabajo = a;
}

fecha operario::get_ult_trabajo() { //Retornar última fecha de trabajo
    return ult_trabajo;
}

void operario::editaroperador() {
    int x = 0;
    string aux;
    fecha aux1;
    do {
        cout << "1- Nombre. " <<endl;
        cout << "2- ID." << endl;
        cout << "3. Última fecha de trabajo." << endl;
        cin >> x;

        fflush(stdin);
        switch (x){
            case 1:
                cout << "Por favor, ingrese el nombre del operador: " << endl;
                getline(cin, aux);
                fflush(stdin);

                nombre = aux;
                x = 1;
                break;

            case 2:
                cout << "Por favor, ingrese el ID del operador: " << endl;
                cin >> aux;

                id = aux;
                x = 1;
                break;

            case 3:
                cout << "Por favor, ingrese la última fecha de trabajo del operador: " << endl;
                cin >> aux1;
                ult_trabajo = aux1;
                x = 1;
                break;

            default:
                cout << "La opción elegida no coincide con ninguno de los datos posibles, inténtelo nuevamente" << endl;
                x = 0;
        }
    } while (x == 0);
}

//Sobrecargas de entrada y salida
ostream &operator<<(ostream &out, const operario &a){
    out << "Nombre: " << a.nombre << endl;
    out << "ID: " << a.id << endl;
    out << "Placa de máquina encargada: " << a.maquina << endl;
    out << "Fecha de su último trabajo: " << a.ult_trabajo << endl;

    return out;
}

istream &operator>>(istream &in, operario &a){
    cout << "Por favor, ingrese el nombre del operador:  ";
    getline(in, a.nombre);
    cout << "Por favor, ingrese el ID del operador:  ";
    in >> a.id;
    cout << "Por favor, ingrese la placa de la máquina que opera:  ";
    in >> a.maquina;
    cout << "Por favor, ingrese su última fecha de trabajo:\n";
    in >> a.ult_trabajo;

    fflush(stdin);
    return in;
}

//sobrecarga de otros operadores
const operario &operario::operator=(const operario &igual) {
    nombre = igual.nombre;
    id = igual.id;
    maquina = igual.maquina;
    ult_trabajo = igual.ult_trabajo;

    return *this;
}