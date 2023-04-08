#include "fecha.h"

const int fecha::dias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

fecha::fecha(int m, int d, int a) {
    estableceFecha(m, d, a);
}

fecha::fecha(const fecha &copia)
{
    dia = copia.dia;
    mes = copia.mes;
    anio = copia.anio;
}

fecha::~fecha() = default;

void fecha::estableceFecha(int mm, int dd, int aa)
{
    mes = (mm >= 1 && mm <= 12)? mm : 1;
    anio = (aa >= 1900 && aa <= 2100)? aa : 1900;

    if(mes == 2 && anioBisiesto(anio))
        dia = (dd >= 1 && dd <= 29)? dd : 1;
    else
        dia = (dd >= 1 && dd <= dias[mes])? dd : 1;
}

fecha &fecha::operator++()
{
    ayudaIncremento();
    return *this;
}

fecha fecha::operator++(int)
{
    fecha temp = *this;
    ayudaIncremento();
    return temp;
}

const fecha &fecha::operator+=(int diasAdicionales)
{
    for(int i = 0; i < diasAdicionales; i++)
        ayudaIncremento();

    return *this;
}

bool fecha::anioBisiesto(int verificaAnio) const
{
    if(verificaAnio % 400 == (verificaAnio % 100 != 0 && verificaAnio % 4 == 0))
        return true;
    else
        return false;
}

bool fecha::finDeMes(int verificaDia) const
{
    if(mes == 2 && anioBisiesto(anio))
        return verificaDia == 29;
    else
        return verificaDia == dias[mes];
}

void fecha::ayudaIncremento()
{
    if(!finDeMes(dia))
        ++dia;
    else
    if(mes < 12){
        ++mes;
        dia = 1;
    }
    else{
        ++anio;
        mes = 1;
        dia = 1;
    }
}

ostream &operator<<(ostream &salida, const fecha &d)
{
    string nomM[13]={"","Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic"};
    salida<<nomM[d.mes]<<" "<<d.dia<<", "<<d.anio;
    return salida;
}

istream &operator>>(istream &entrada, fecha &d) {
    cout << "Día = ";
    entrada >> d.dia;

    cout << "Mes = ";
    entrada >> d.mes;

    cout << "Año = ";
    entrada >> d.anio;

    d.estableceFecha(d.mes,d.dia,d.anio);

    return entrada;
}