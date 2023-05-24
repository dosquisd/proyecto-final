#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <vector>
using namespace std;

class fecha {
    friend ostream &operator<<(ostream &, const fecha &);
    friend istream &operator>>(istream &, fecha &);
    friend fecha& to_fecha(string); // Convertir una cadena dd/mm/aaaa, a un objeto fecha

public:
    fecha(int m = 1, int d = 1, int y = 1900);
    fecha(const fecha &);
    virtual ~fecha();

    void estableceFecha(int, int, int);

    fecha &operator++();
    fecha operator++(int);
    const fecha &operator+=(int);

    const bool operator <(const fecha);
    const bool operator >(const fecha);

    bool anioBisiesto(int) const;
    bool finDeMes(int) const;

    int get_dia() const;
    int get_mes() const;
    int get_anio() const;

private:
    int mes;
    int dia;
    int anio;

    static const int dias[];

    void ayudaIncremento();
};


#endif // FECHA_H
