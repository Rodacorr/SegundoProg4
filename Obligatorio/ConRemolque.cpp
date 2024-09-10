#include "ConRemolque.h"
//constructor por defecto del camion con remolque
ConRemolque :: ConRemolque() : Grande()
{
    capRemolque = 0;
}
//constructor comun del camion con remolque
ConRemolque :: ConRemolque(String enrollment,String brand,int annualTravels,Camionero * cam,float vol,Fecha date,float cap) : Grande(enrollment,brand,annualTravels,cam,vol,date)
{
    capRemolque = cap;
}
//constructor de copia del camion con remolque
ConRemolque :: ConRemolque(const ConRemolque &otro) : Grande(otro)
{
    capRemolque = otro.capRemolque;
}
//selectora de la capacidad del camion con remolque
float ConRemolque :: getCapRemolque()
{
    return capRemolque;
}
//modificador de la capacidad del camion con remolque
void ConRemolque :: setCapRemolque(float cap)
{
    capRemolque = cap;
}
//retorna el tipo de objeto
String ConRemolque :: getTipoObjeto()
{
    return "ConRemolque";
}
//cantidad de metros cúbicos anuales que el camion simple es capaz de transportar
float ConRemolque :: cantMetrosCub()
{
    float capMetrosCub = Grande :: cantMetrosCub();
    return (capMetrosCub + capRemolque);
}
//destructor del camion con remolque
ConRemolque :: ~ConRemolque()
{
}
