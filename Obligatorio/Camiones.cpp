#include "Camiones.h"
//constructor por defecto de camiones
Camiones :: Camiones()
{
    for(int i=0; i<B; i++)
        crearLista(Hash[i]);
}
//funcion de dispersion
int Camiones :: h(String enrollment)
{
    int key = enrollment.ConvertStringToInt();
    return (key % B);
}
//incializar lista vacia
void Camiones :: crearLista(NodoH * &lis)
{
    lis = NULL;
}
//primitiva del diccionario, dada una matricula retorna si existe o no el camion
bool Camiones :: MemberHash(String enrollment)
{
    int cubeta = h(enrollment);
    return perteneceLista(Hash[cubeta],enrollment);
}
//dado una matricula retorna si existe en una lista
bool Camiones :: perteneceLista(NodoH * lis, String enrollment)
{
    bool existe = false;
    while(!existe && lis != NULL)
    {
        if(lis->info->getMatricula() == enrollment)
            existe = true;
        else
            lis = lis->sig;
    }
    return existe;
}
//primitiva del diccionario, inserta un nuevo camion en el hash de camiones
void Camiones :: InsertHash(Camion * cam)
{
    int cubeta = h(cam->getMatricula());
    InsFront(Hash[cubeta],cam);
}
//inserta un nuevo elemento en la lista
void Camiones :: InsFront(NodoH * &lis,Camion * cam)
{
    NodoH * nuevo = new NodoH;
    nuevo->info = cam;
    nuevo->sig = lis;
    lis = nuevo;
}
//primitiva del diccionario, retorna un * camion si existe en el hash de camiones
Camion * Camiones :: FindHash(String enrollment)
{
    int cubeta = h(enrollment);
    return buscarLista(Hash[cubeta],enrollment);
}
//busca un elemento en la lista, si lo encuentra lo retorna
Camion * Camiones :: buscarLista(NodoH * lis,String enrollment)
{
    while(!(lis->info->getMatricula() == enrollment))
        lis = lis->sig;
    return (lis->info);
}
//primitiva del diccionario, sustituye un camion por otro
void Camiones :: ModifyHash(Camion * cam)
{
    int cubeta = h(cam->getMatricula());
    moficarLista(Hash[cubeta],cam);
}
//modifica la lista, cambiando un elemento por otro
void Camiones :: moficarLista(NodoH * &lis,Camion * cam)
{
    Camion * old = FindHash(cam->getMatricula());
    old = cam;
}
 //primitiva del diccionario, dado una matricula elimina el camion con dicha matricula
void Camiones :: DeleteHash(String enrollment)
{
    int cubeta = h(enrollment);
    borrarElemento(Hash[cubeta],enrollment);
}
//elimina elemento de la lista dado una matricula
void Camiones :: borrarElemento(NodoH * &lis, String enrollment)
{
    while(!(lis->info->getMatricula() == enrollment))
        lis = lis->sig;
    NodoH * aux = lis;
    lis = lis->sig;
    delete aux;
}
//borrar todos los elementos del hash
void Camiones :: destruirHash(NodoH * &lis)
{
    while(lis != NULL)
    {
        NodoH * aux = lis;
        lis = lis->sig;
        delete aux;
    }
}
//retorna la cantidad total de metros cubicos que puede transportar toda la flota de camioneros
float Camiones :: cantTotalMetrosCubicos()
{
    float total = 0;
    for(int i=0;i<B;i++)
        total = total + cantTotalMetrosCubLista(Hash[i]);
    return total;
}
//operacion auxiliar de cantTotalMetrosCubicos
float Camiones :: cantTotalMetrosCubLista(NodoH * lis)
{
    float total = 0;
    while(lis != NULL)
    {
        total = total + lis->info->cantMetrosCub();
        lis = lis->sig;
    }
    return total;
}
//cantidad de cada tipo de camion en la flota de camiones
void Camiones :: cantTiposCamiones(int &simple,int &grande,int &conRemolque)
{
    simple = 0;
    grande = 0;
    conRemolque = 0;
    for(int i=0;i<B;i++)
        cantTiposCamionesLista(Hash[i],simple,grande,conRemolque);
}
//cantidad de cada tipo de camion en la lista
void Camiones :: cantTiposCamionesLista(NodoH * lis,int &simple,int &grande,int &conRemolque)
{
    while(lis != NULL)
    {
        if(lis->info->getTipoObjeto() == "Simple")
        {
            simple++;
        }else if(lis->info->getTipoObjeto() == "Grande")
        {
            grande++;
        }else
        {
            conRemolque++;
        }
        lis = lis->sig;
    }
}
//dada una fecha cuenta cuantos camiones grandes hay registrados cuya fecha de adquisicion es posterior a dicha fecha
int Camiones :: cantCamionesGrandesXFecha(Fecha date)
{
    int cant = 0;
    for(int i=0;i<B;i++)
        cant = cant + cantCamionesGrandesXFechaLista(Hash[i],date);
    return cant;
}
//dada una fecha cuenta cuantos camiones grandes hay registrados cuya fecha de adquisicion es posterior a dicha fecha en la lista
int Camiones :: cantCamionesGrandesXFechaLista(NodoH * lis,Fecha date)
{
    int cant = 0;
    while(lis != NULL)
    {
        if(lis->info->getTipoObjeto() == "Grande")
        {
            Fecha adquirido = ((Grande *) lis->info)->getFechaAdquirido();
            if(date < adquirido)
                cant++;
        }
        lis = lis->sig;
    }
    return cant;
}
//carga el iterador para luego listarlo en la capa grafica
void Camiones :: listarCamiones(Iterador &iter)
{
    for(int i=0;i<B;i++)
        cargarIteradorCamiones(Hash[i],iter);
}
//operacion auxiliar de la operacion listarCamioneros
void Camiones :: cargarIteradorCamiones(NodoH * lis,Iterador &iter)
{
    while(lis != NULL)
    {
        iter.insertar(lis->info);
        lis = lis->sig;
    }
}
//destructor
Camiones :: ~Camiones()
{
    for(int i=0;i<B;i++)
        destruirHash(Hash[i]);
}
