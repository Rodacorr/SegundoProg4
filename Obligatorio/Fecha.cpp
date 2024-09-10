#include "Fecha.h"
//incrementar fecha operacion auxiliar
Fecha Fecha :: incrementarFecha()
{
    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (dia == 31)
        {
            dia = 1;
            if (mes == 12)
            {
                anio++;
                mes = 1;
            }
            else
                mes++;
        }
        else
            dia++;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (dia == 30)
        {
            dia = 1;
            mes++;
        }
        else
            dia++;
        break;
    case 2:
        if (((anio % 4 == 0) && (anio % 100 != 0)) ||
                (anio % 400 == 0))
        {
            if (dia == 29)
            {
                dia = 1;
                mes++;
            }
            else
                dia++;
        }
        else if (dia == 28)
        {
            dia = 1;
            mes++;
        }
        else
            dia++;
    }
    return (*this);
}
//constructor por defecto
Fecha :: Fecha()
{
    dia = 0;
    mes = 0;
    anio = 0;
}

//constructor comun
Fecha :: Fecha(int d,int m,int y)
{
    dia = d;
    mes = m;
    anio = y;
}

//constructor de copia
Fecha :: Fecha(const Fecha &date)
{
    dia = date.dia;
    mes = date.mes;
    anio = date.anio;
}

//selectora, retorna dia
int Fecha :: getDia()
{
    return dia;
}

//selectora, retorna mes
int Fecha :: getMes()
{
    return mes;
}
//selectora, retorna anio
int Fecha :: getAnio()
{
    return anio;
}

//operacion de sobrecarga del operador <
bool Fecha :: operator<(Fecha f)
{
    bool menor = true;
    if(anio < f.anio)
        menor = true;
    else
    {
        if(anio == f.anio)
        {
            if(mes < f.mes)
                menor = true;
            else
            {
                if(mes == f.mes)
                {
                    if(dia < f.dia)
                        menor = true;
                    else
                    {
                        if((dia == f.dia)||(dia > f.dia))
                            menor = false;
                    }
                }
                else
                    menor = false;
            }
        }
        else
            menor = false;
    }
    return menor;
}
//operacion de sobrecarga del operador ==
bool Fecha :: operator==(Fecha f)
{
    return ((dia == f.dia)&&(mes == f.mes)&&(anio == f.anio));
}
//operacion de sobrecarga del operador ++
Fecha Fecha :: operator++()
{
    incrementarFecha();
    return (*this);
}
Fecha Fecha :: operator++(int)
{
    Fecha temp = (*this);
    incrementarFecha();
    return temp;
}
//retorna una fecha con n dias sumados
Fecha Fecha :: operator+(int num)
{
    Fecha temp = (*this);
    for(int i=1; i<=num; i++)
        temp.incrementarFecha();
    return temp;
}
//devuelve la diferencia de dias entre dos fechas
int Fecha :: operator-(Fecha f)
{
    Fecha aux;
    int signo = 1;
    int cont = 0;
    if((*this) < f)
    {
        for(aux = (*this); aux < f; aux++)
            cont++;
    }
    else
    {
        for(aux = f; aux < (*this); aux++)
            cont++;
    }
    return (signo * cont);
}
//determina si una fecha es valida o no
bool Fecha :: esValida()
{
    bool valida = true;
    if (anio < 1900 || anio > 2099)
        valida = false;
    else
    {
        switch (mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            valida = (dia < 1 || dia > 31);
                 break;
        case 4:
        case 6:
        case 9:
        case 11:
            valida = (dia < 1 || dia > 30);
                 break;
        case 2:
            if (((anio % 4 == 0) && (anio % 100 != 0)) ||
                    (anio % 400 == 0))
                valida = (dia < 1 || dia > 29);
            else
                valida = (dia < 1 || dia > 28);
        }
    }
    return valida;
}
//mostrar por pantalla Fecha
void Fecha :: mostrarFecha()
{
    printf("\nDia: %d",dia);
    printf("\nMes: %d",mes);
    printf("\nAnio: %d",anio);
}
