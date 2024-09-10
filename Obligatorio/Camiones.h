#ifndef CAMIONES_H_INCLUDED
#define CAMIONES_H_INCLUDED
#include "Camion.h"
#include "Grande.h"
#include "Simple.h"
#include "ConRemolque.h"
#include "Iterador.h"
const int B = 100;
class Camiones
{
    private:
        struct NodoH{
                        Camion * info;
                        NodoH * sig;
                    };
                NodoH * Hash[B];
    public:
        //constructor por defecto de camiones
        Camiones();
        //funcion de dispersion
        int h(String);
        //incializar lista vacia
        void crearLista(NodoH * &);
        //primitiva del diccionario, dada una matricula retorna si existe o no el camion
        bool MemberHash(String);
        //dado una matricula retorna si existe en una lista
        bool perteneceLista(NodoH *,String);
        //primitiva del diccionario, inserta un nuevo camion en el hash de camiones
        void InsertHash(Camion *);
        //inserta un nuevo elemento en la lista
        void InsFront(NodoH * &,Camion *);
        //primitiva del diccionario, retorna un * camion si existe en el hash de camiones
        Camion * FindHash(String);
        //busca un elemento en la lista, si lo encuentra lo retorna
        Camion * buscarLista(NodoH *,String);
        //primitiva del diccionario, sustituye un camion por otro
        void ModifyHash(Camion *);
        //modifica la lista, cambiando un elemento por otro
        void moficarLista(NodoH * &,Camion *);
        //primitiva del diccionario, dado una matricula elimina el camion con dicha matricula
        void DeleteHash(String);
        //elimina elemento de la lista dado una matricula
        void borrarElemento(NodoH * &lis, String);
        //borrar todos los elementos del hash
        void destruirHash(NodoH * &);
        //retorna la cantidad total de metros cubicos que puede transportar toda la flota de camioneros
        float cantTotalMetrosCubicos();
        //operacion auxiliar de cantTotalMetrosCubicos
        float cantTotalMetrosCubLista(NodoH *);
        //cantidad de cada tipo de camion en la flota de camiones
        void cantTiposCamiones(int &,int &,int &);
        //cantidad de cada tipo de camion en la lista
        void cantTiposCamionesLista(NodoH *,int &,int &,int &);
        //dada una fecha cuenta cuantos camiones grandes hay registrados cuya fecha de adquisicion es posterior a dicha fecha
        int cantCamionesGrandesXFecha(Fecha);
        //dada una fecha cuenta cuantos camiones grandes hay registrados cuya fecha de adquisicion es posterior a dicha fecha en la lista
        int cantCamionesGrandesXFechaLista(NodoH * lis,Fecha);
        //carga el iterador para luego listarlo en la capa grafica
        void listarCamiones(Iterador &);
        //operacion auxiliar de la operacion listarCamioneros
        void cargarIteradorCamiones(NodoH *,Iterador &);
        //destructor
        ~Camiones();

};
#endif // CAMIONES_H_INCLUDED
