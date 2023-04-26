#include "equipo_mantenimiento.h"

//Métodos generales

equipo_mantenimiento::equipo_mantenimiento(int a) { //Constructor
    integrantes = (a <= 3) ? 3 : a; //Validación para segurar que la cantidad mínima de integrantes de un equipo de mantenimiento es 3
    equipo.resize(integrantes); //Se inicializa el vector con el tamaño de los integrantes
    nombre_equipo = "0";
}

equipo_mantenimiento::equipo_mantenimiento(const equipo_mantenimiento &copia) {//constructor de copia
    integrantes = copia.integrantes;
    nombre_equipo = copia.nombre_equipo;

    equipo.resize(copia.equipo.size());
    copy(copia.equipo.begin(), copia.equipo.end(), equipo.begin());
}

equipo_mantenimiento::~equipo_mantenimiento() {
    equipo.clear();
} //Destructor

//métodos específicos
void equipo_mantenimiento::set_operarios() { //Establecer operarios
    for (int i = 0; i < equipo.size(); i++){
        cout << " -------------- Integrante N°" << i+1 << " -------------- " << endl;
        cin >> equipo[i];
    }
}

void equipo_mantenimiento::set_nombre_equipo(string a) {//Establecer nombre del equipo
    nombre_equipo = a;
}

string equipo_mantenimiento::get_nombre() const { //Retornar nombre del equipo
    return nombre_equipo;
}

void equipo_mantenimiento::set_integrantes(int a) { //Establecer el número de integrantes
    integrantes = a;
}

int equipo_mantenimiento::get_integrantes() const { //Retornar cantidad de integrantes
    return integrantes;
}

void equipo_mantenimiento::actualizar_operario() {
    int aux = 0;

    do {
        cout << this;
        cout << "Por favor, ingrese el número relacionado con el integrante que desea modificar ";
        cin >> aux;
    } while (aux>integrantes || aux<1); //Ciclo condicionado para asegurar que el valor indicado está dentro del rango de integrantes

    cin >> equipo[aux-1]; //Se solicita la entrada de los nuevos datos.
}

void equipo_mantenimiento::agregar_operario(const operario &a) {
    equipo.push_back(a);
}

//sobrecarga de salida
ostream &operator<<(ostream &out, const equipo_mantenimiento &a){
    for (int i = 0; i < a.equipo.size(); i++){
        out << " -------------- Integrante N°" << i+1 << " -------------- " << endl;
        out << a.equipo[i] << endl;
    }

    return out;
}

istream &operator>>(istream &in, equipo_mantenimiento &a) {
    // En caso de ser necesario, se puede guardar tambien el nombre del equipo o el numero de operarios (o ambos)
    for(int i = 0; i < a.integrantes; i++) {
        cout << "Integrante N°" << i+1 << endl;
        in >> a.equipo[i];
        cout << endl;
    }

    return in;
}