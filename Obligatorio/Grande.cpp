#include "Grande.h"
//constructor por defecto del camion grande
Grande :: Grande() : fechaAdquirido()
{
    volumen = 0;
}
//constructor comun del camion grande
Grande :: Grande(String enrollment,String brand,int annualTravels,Camionero * cam,float vol,Fecha date) : Camion(enrollment,brand,annualTravels,cam)
{
    volumen = vol;
    fechaAdquirido = date;
}
//constructor de copia del camion grande
Grande :: Grande(const Grande &otro) : Camion(otro)
{
    volumen = otro.volumen;
    fechaAdquirido = otro.fechaAdquirido;
}
//selectora del volumen del camion grande
float Grande :: getVolumen()
{
    return volumen;
}
//selectora de la fecha adquirido del camion grande
Fecha Grande :: getFechaAdquirido()
{
    return fechaAdquirido;
}
//modificador del volumen del camion grande
void Grande :: setVolumen(float vol)
{
    volumen = vol;
}
//modificador de la fecha adquirido del camion grande
void Grande :: setFechaAdquirido(Fecha date)
{
    fechaAdquirido = date;
}
//retorna el tipo de objeto
String Grande :: getTipoObjeto()
{
    return "Grande";
}
//cantidad de metros cúbicos anuales que el camion simple es capaz de transportar
float Grande :: cantMetrosCub()
{
    int annualTravels = Camion :: getCantViajesAnuales();
    return (annualTravels * volumen);
}
//destructor del camion grande
Grande :: ~Grande()
{
}
