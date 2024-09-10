#include "Camionero.h"
//constructor por defecto del camionero
Camionero :: Camionero() : nombre(),fechaNacimiento()
{
    cedula = 0;
    cantTatuajes = 0;
}
//constructor común del camionero
Camionero :: Camionero(long int ci,String name,int cantTattoo, Fecha nac)
{
    cedula = ci;
    nombre = name;
    cantTatuajes = cantTattoo;
    fechaNacimiento = nac;
}
//constructor de copia del camionero
Camionero :: Camionero(const Camionero &otro)
{
    cedula = otro.cedula;
    nombre = otro.nombre;
    cantTatuajes = otro.cantTatuajes;
    fechaNacimiento = otro.fechaNacimiento;
}
//selectora cedula del camionero
long int Camionero :: getCedula()
{
    return cedula;
}
//selectora nombre del camionero
String Camionero :: getNombre()
{
    return nombre;
}
//selectora cantidad tatuajes del camionero
int Camionero :: getCantTatuajes()
{
    return cantTatuajes;
}
//selectora fecha de nacimiento del camionero
Fecha Camionero :: getFechaNacimiento()
{
    return fechaNacimiento;
}
//modificador cedula del camionero
void Camionero :: setCedula(long int ci)
{
    cedula = ci;
}
//modificador nombre del camionero
void Camionero :: setNombre(String name)
{
    nombre = name;
}
//modificador cantidad tatuajes del camionero
void Camionero :: setCantTatuajes(int cantTattoo)
{
    cantTatuajes = cantTattoo;
}
//modificador fecha de nacimiento del camionero
void Camionero :: setFechaNacimiento(Fecha nac)
{
    fechaNacimiento = nac;
}
//retorna el tipo de objeto
String Camionero :: getTipoObjeto()
{
    return "Camionero";
}
//destructor del camionero
Camionero :: ~Camionero()
{

}
