#ifndef ITERADOR_H_INCLUDED
#define ITERADOR_H_INCLUDED
#include "Objeto.h"
class Iterador{
    private:
            struct NodoL{
                        Objeto * info;
                        NodoL * sig;
            };
            NodoL * prim;
            NodoL * ulti;
            NodoL * actual;
    public:
        //constructor por defecto del Iterador
        Iterador();
        //insertar un elemento en el iterador
        void insertar(Objeto *);
        //retorna el siguiente objeto del iterador
        Objeto * siguienteObjeto();
        //retorna si hay mas objetos en el iterador
        bool hayMasObjetos();
        //destructor
        ~Iterador();
};

#endif // ITERADOR_H_INCLUDED
