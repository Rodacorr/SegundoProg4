#include "Camioneros.h"
//constructor por defecto de camioneros
Camioneros :: Camioneros()
{
    ABB = NULL;
}
//primitiva del diccionario, dado una cedula determina si existe el camionero en el ABB
bool Camioneros :: MemberABB(long int ci)
{
    return perteneceABB(ABB,ci);
}
//operacion auxiliar de la primitiva member
bool Camioneros :: perteneceABB(Nodo * a,long int ci)
{
    bool existe = false;
    while(!existe && a!= NULL)
    {
        if(ci == a->info->getCedula())
            existe = true;
        else
        {
            if(ci < a->info->getCedula())
                a = a->hizq;
            else
                a = a->hder;
        }
    }
    return existe;
}
//primitiva del diccionario, inserta un nuevo camionero en el ABB
void Camioneros :: InsertABB(Camionero * cam)
{
    insertarEnABB(ABB,cam);
}
//operacion auxiliar de la primitiva insert
void Camioneros :: insertarEnABB(Nodo * &a, Camionero * cam)
{
    if(a == NULL)
    {
        a = new Nodo;
        a->info = cam;
        a->hizq = NULL;
        a->hder = NULL;
    }
    else
    {
        if(cam->getCedula() < a->info->getCedula())
            insertarEnABB(a->hizq,cam);
        else
            insertarEnABB(a->hder,cam);
    }
}
//primitiva del diccionario, dada una cedula si existe en el ABB retorna el camionero
Camionero * Camioneros :: FindABB(long int ci)
{
    return buscarEnABB(ABB,ci);
}
//operacion auxiliar de la primitiva find
Camionero * Camioneros :: buscarEnABB(Nodo * a,long int ci)
{
    if(a->info->getCedula() == ci)
        return a->info;
    else
    {
        if(ci < a->info->getCedula())
            return buscarEnABB(a->hizq,ci);
        else
            return buscarEnABB(a->hder,ci);
    }
}
//primitiva del diccionario, sustituye un camionero por otro
void Camioneros :: ModifyABB(Camionero * cam)
{
    modificarABB(ABB,cam);
}
//operacion auxiliar de la primitiva modify
void Camioneros :: modificarABB(Nodo * &a,Camionero * cam)
{
    Camionero * old = FindABB(cam->getCedula());
    old = cam;
}
//primitiva del diccionario, dado una cedula elimina al camionero con dicha cedula
void Camioneros :: DeleteABB(long int ci)
{
    eliminarElementoABB(ABB,ci);
}
//borra el minimo elemento del ABB
void Camioneros :: BorrarMinimo(Nodo * &a)
{
    Nodo * aux;
    if(a->hizq == NULL)
    {
        aux = a->hder;
        delete a;
        a = aux;
    }
    else
        BorrarMinimo(a->hizq);
}
//retorna el minimo elemento del ABB
Camionero * Camioneros :: Minimo(Nodo * a)
{
    if(a->hizq == NULL)
        return (a->info);
    else
        return Minimo(a->hizq);
}
//operacion auxiliar de la primitiva delete
void Camioneros :: eliminarElementoABB(Nodo * &a,long int ci)
{
    Nodo * aux;
    if(a->info->getCedula() == ci)
    {
        if(a->hder == NULL)
        {
            aux = a->hizq;
            delete a;
            a = aux;
        }
        else
        {
            if(a->hizq == NULL)
            {
                aux = a->hder;
                delete a;
                a = aux;
            }
            else
            {
                a->info = Minimo(a->hder);
                BorrarMinimo(a->hder);
            }
        }
    }
    else
    {
        if(ci < a->info->getCedula())
            eliminarElementoABB(a->hizq,ci);
        else
            eliminarElementoABB(a->hder,ci);
    }
}
//elimina la memoria reservada por la coleccion de los elementos
void Camioneros :: destruirABB(Nodo * &a)
{
    if(a != NULL)
    {
        destruirABB(a->hizq);
        destruirABB(a->hder);
        delete (a->info);
        delete (a);
        a = NULL;
    }
}
//lista todos los camioneros almacenados en el ABB ordenandolos por cedula
void Camioneros :: listarCamioneros(Iterador &iter)
{
    cargarIterador(ABB,iter);
}
//operacion auxiliar de la operacion listarCamioneros
void Camioneros :: cargarIterador(Nodo * a,Iterador &iter)
{
    if(a != NULL)
    {
        cargarIterador(a->hizq,iter);
        iter.insertar(a->info);
        cargarIterador(a->hder,iter);
    }
}
//retorna el camionero con mayor cantidad de tatuajes
void Camioneros :: camioneroMasTattoo(Camionero * &cam)
{
    int mayor = 0;
    camioneroMasTattooArbol(ABB,mayor,cam);
}
//operacion auxiliar, retorna el camionero con mayor cantidad de tatuajes
void Camioneros :: camioneroMasTattooArbol(Nodo * a, int &mayor,Camionero * &cam)
{
    if(a != NULL)
    {
        camioneroMasTattooArbol(a->hizq,mayor,cam);
        if(mayor < a->info->getCantTatuajes())
        {
            mayor = a->info->getCantTatuajes();
            cam = a->info;
        }
        camioneroMasTattooArbol(a->hder,mayor,cam);
    }
}
//retorna si el ABB esta vacio
bool Camioneros :: estaVacioABB()
{
    return (ABB == NULL);
}
//destructor
Camioneros :: ~Camioneros()
{
    destruirABB(ABB);
}
