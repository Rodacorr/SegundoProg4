#include "Camion.h"
 //constructor por defecto del camion
Camion :: Camion() : matricula(),marca(),camionero()
{
    cantViajesAnuales = 0;
}
//constructor comun del camion
Camion :: Camion(String enrollment,String brand,int annualTravels,Camionero * cam)
{
    matricula = enrollment;
    marca = brand;
    cantViajesAnuales = annualTravels;
    camionero = cam;
}
//constructor de copia del camion
Camion :: Camion(const Camion &otro)
{
    matricula = otro.matricula;
    marca = otro.marca;
    cantViajesAnuales = otro.cantViajesAnuales;
    camionero = otro.camionero;
}
//selectora de la matricula del camion
String Camion :: getMatricula()
{
    return matricula;
}
//selectora de la marca del camion
String Camion :: getMarca()
{
    return marca;
}
//selectora de la cantidad de viajes anuales del camion
int Camion :: getCantViajesAnuales()
{
    return cantViajesAnuales;
}
//selectora del  camionero del camion
Camionero * Camion :: getCamionero()
{
    return camionero;
}
//modificador de la matricula del camion
void Camion :: setMatricula(String enrollment)
{
    matricula = enrollment;
}
//modificador de la marca del camion
void Camion :: setMarca(String brand)
{
    marca = brand;
}
//modificador de la cantidad de viajes anuales del camion
void Camion :: setCantViajesAnuales(int annualTravels)
{
    cantViajesAnuales = annualTravels;
}
//modificador del  camionero del camion
void Camion :: setCamionero(Camionero * cam)
{
    camionero = cam;
}
//destructor del camion
Camion :: ~Camion()
{

}
