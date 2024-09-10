#ifndef CAMIONEROS_H_INCLUDED
#define CAMIONEROS_H_INCLUDED
#include "Camionero.h"
#include "Iterador.h"
class Camioneros{
    private:
            struct Nodo{
                            Camionero * info;
                            Nodo * hizq;
                            Nodo * hder;
                        };
                        Nodo * ABB;
    public:
        //constructor por defecto de camioneros
        Camioneros();
        //primitiva del diccionario, dado una cedula determina si existe el camionero en el ABB
        bool MemberABB(long int);
        //operacion auxiliar de la primitiva member
        bool perteneceABB(Nodo *,long int);
        //primitiva del diccionario, inserta un nuevo camionero en el ABB
        void InsertABB(Camionero *);
        //operacion auxiliar de la primitiva insert
        void insertarEnABB(Nodo * &, Camionero *);
        //primitiva del diccionario, dada una cedula si existe en el ABB retorna el camionero
        Camionero * FindABB(long int);
        //operacion auxiliar de la primitiva find
        Camionero * buscarEnABB(Nodo *,long int);
        //primitiva del diccionario, sustituye un camionero por otro
        void ModifyABB(Camionero *);
        //operacion auxiliar de la primitiva modify
        void modificarABB(Nodo * &,Camionero *);
        //primitiva del diccionario, dado una cedula elimina al camionero con dicha cedula
        void DeleteABB(long int);
        //borra el minimo elemento del ABB
        void BorrarMinimo(Nodo * &);
        //retorna el minimo elemento del ABB
        Camionero * Minimo(Nodo *);
        //operacion auxiliar de la primitiva delete
        void eliminarElementoABB(Nodo *&,long int);
        //elimina la memoria reservada por la coleccion de los elementos
        void destruirABB(Nodo * &);
        //carga el iterador para luego listarlo en la capa grafica
        void listarCamioneros(Iterador &);
        //operacion auxiliar de la operacion listarCamioneros
        void cargarIterador(Nodo *,Iterador &);
        //retorna el camionero con mayor cantidad de tatuajes
        void camioneroMasTattoo(Camionero * &);
        //operacion auxiliar, retorna el camionero con mayor cantidad de tatuajes
        void camioneroMasTattooArbol(Nodo *,int &,Camionero * &);
        //retorna si el ABB esta vacio
        bool estaVacioABB();
        //destructor
        ~Camioneros();
};

#endif // CAMIONEROS_H_INCLUDED
