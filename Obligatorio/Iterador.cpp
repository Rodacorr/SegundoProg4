#include "Iterador.h"
//constructor por defecto del Iterador
Iterador :: Iterador()
{
    prim = NULL;
    ulti = NULL;
    actual = NULL;
}
//insertar un elemento en el iterador
void Iterador :: insertar(Objeto * obj)
{
    NodoL * nuevo = new NodoL;
    nuevo->info = obj;
    nuevo->sig = NULL;
    if(prim == NULL)
    {
        prim = nuevo;
        ulti = nuevo;
        actual = nuevo;
    }else
    {
        ulti->sig = nuevo;
        ulti = ulti->sig;
    }
}
//retorna el siguiente objeto del iterador
Objeto * Iterador :: siguienteObjeto()
{
    Objeto * obj = actual->info;
    actual = actual->sig;
    return obj;
}
//retorna si hay mas objetos en el iterador
bool Iterador :: hayMasObjetos()
{
    return (bool)(actual != NULL);
}
//destructor
Iterador :: ~Iterador()
{
    NodoL * aux = prim;
    while(aux != NULL)
    {
        prim = prim->sig;
        delete aux;
        aux = prim;
    }
}
