#include "Fachada.h"
//constructor por defecto de la fachada
Fachada :: Fachada() : diccA(), diccH()
{
}
void Fachada :: registrarCamion(Camion * cam,long int cedula,int &error)
{
    if(!(diccH.MemberHash(cam->getMatricula())))
    {
        if(diccA.MemberABB(cedula))
        {
            Camionero * camionero = diccA.FindABB(cedula);
            cam->setCamionero(camionero);
            diccH.InsertHash(cam);
        }
        else
        {
            error = 0;
        }
    }else
    {
        error = 1;
    }
}
//Retorna un iterador con los camiones cargados en el sistema para luego ser mostrados en la capa grafica
Iterador Fachada :: listarCamiones()
{
    Iterador iter;
    diccH.listarCamiones(iter);
    return iter;
}
//en base a una matricula, retorna un camion para luego ser mostrado por pantalla por la capa grafica
void Fachada :: datosCamionXMatricula(String enrollment,Camion * &cam, int &error)
{
    if(diccH.MemberHash(enrollment))
        cam = diccH.FindHash(enrollment);
    else
        error = 6;
}
//registrar un nuevo camionero en el sistema
void Fachada :: registrarCamionero(Camionero * cam, int &error)
{
    if(!(diccA.MemberABB(cam->getCedula())))
        diccA.InsertABB(cam);
    else
        error = 4;
}
//retorna un iterador con los camioneros cargados en el sistema para luego mostrarlos en la capa grafica
Iterador Fachada :: listarCamioneros()
{
    Iterador iter;
    diccA.listarCamioneros(iter);
    return iter;
}
//retorna la cantidad total de metros cubicos que puede transportar toda la flota de camioneros
float Fachada :: sumaTotalMetrosCub()
{
    return diccH.cantTotalMetrosCubicos();
}
//modifica la cantidad de viajes anuales de un camion dada su matricula
void Fachada :: setCantViajesAnualesXMatricula(String enrollment,int x,int &error)
{
    if(diccH.MemberHash(enrollment))
    {
        Camion * cam = diccH.FindHash(enrollment);
        cam->setCantViajesAnuales(x);
    }else
        error = 6;
}
//cantidad de cada tipo de camion en la flota de camiones
void Fachada :: cantTiposCamiones(int &simple,int &grande,int &conRemolque)
{
    diccH.cantTiposCamiones(simple,grande,conRemolque);
}
//retorna el camionero con mayor cantidad de tatuajes
void Fachada :: camioneroConMasTatuajes(Camionero * &cam, int &error)
{
    if(!(diccA.estaVacioABB()))
        diccA.camioneroMasTattoo(cam);
    else
        error = 5;
}
//dada una fecha cuenta cuantos camiones grandes hay registrados cuya fecha de adquisicion es posterior a dicha fecha
int Fachada :: cantCamGrandesRegPostFecha(Fecha date)
{
    return diccH.cantCamionesGrandesXFecha(date);
}
//destructor
Fachada :: ~Fachada()
{
}

