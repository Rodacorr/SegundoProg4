#include "Simple.h"
//constructor por defecto del camion simple
Simple :: Simple() : Camion(), depto()
{
}
//constructor comun del camion simple
Simple :: Simple(String enrollment,String brand,int annualTravels,Camionero * cam,String dpto) : Camion(enrollment,brand,annualTravels,cam)
{
    depto = dpto;
}
//constructor de copia del camion simple
Simple :: Simple(const Simple &otro) : Camion(otro)
{
    depto = otro.depto;
}
//selectora de departamento del camion simple
String Simple :: getDepto()
{
    return depto;
}
//modificador de departamento del camion simple
void Simple :: setDepto(String dpto)
{
    depto = dpto;
}
//retorna el tipo de objeto
String Simple :: getTipoObjeto()
{
    return "Simple";
}
//cantidad de metros cúbicos anuales que el camion simple es capaz de transportar
float Simple :: cantMetrosCub()
{
    int annualTravels = Camion :: getCantViajesAnuales();
    return (annualTravels * 10);
}
