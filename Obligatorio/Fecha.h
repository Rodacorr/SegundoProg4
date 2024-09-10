#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "String.h"
class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    //incrementar fecha operacion auxiliar
    Fecha incrementarFecha();
    //constructor por defecto
    Fecha();
    //constructor comun
    Fecha(int,int,int);
    //constructor de copia
    Fecha(const Fecha &);
    //selectora, retorna dia
    int getDia();
    //selectora, retorna mes
    int getMes();
    //selectora, retorna anio
    int getAnio();
    //operacion de sobrecarga del operador <
    bool operator<(Fecha);
    //operacion de sobrecarga del operador ==
    bool operator==(Fecha);
    //operacion de sobrecarga del operador ++ prefijo
    Fecha operator++();
    //operacion de sobrecarga del operador ++ postfijo
    Fecha operator++(int);
    //retorna una fecha con n dias sumados
    Fecha operator+(int);
    //devuelve la dias de diferencia entre dos fechas
    int operator-(Fecha);
    //determina si una fecha es valida o no
    bool esValida();
    //mostrar por pantalla Fecha
    void mostrarFecha();
};


#endif // FECHA_H_INCLUDED
