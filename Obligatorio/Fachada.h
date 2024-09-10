#ifndef FACHADA_H_INCLUDED
#define FACHADA_H_INCLUDED
#include "Camiones.h"
#include "Camioneros.h"
class Fachada{
    private:
        Camioneros diccA;
        Camiones diccH;
    public:
        //constructor por defecto de la fachada
        Fachada();
        //registrar un nuevo camion en el sistema
        void registrarCamion(Camion *,long int,int &);
        //Retorna un iterador con los camiones cargados en el sistema para luego ser mostrados en la capa grafica
        Iterador listarCamiones();
        //en base a una matricula, retorna un camion para luego ser mostrado por pantalla por la capa grafica
        void datosCamionXMatricula(String,Camion * &,int &);
        //registrar un nuevo camionero en el sistema
        void registrarCamionero(Camionero *,int &);
        //retorna un iterador con los camioneros cargados en el sistema para luego mostrarlos en la capa grafica
        Iterador listarCamioneros();
        //retorna la cantidad total de metros cubicos que puede transportar toda la flota de camioneros
        float sumaTotalMetrosCub();
        //modifica la cantidad de viajes anuales de un camion dada su matricula
        void setCantViajesAnualesXMatricula(String,int,int &);
        //cantidad de cada tipo de camion en la flota de camiones
        void cantTiposCamiones(int &,int &,int &);
        //retorna el camionero con mayor cantidad de tatuajes
        void camioneroConMasTatuajes(Camionero * &,int &);
        //dada una fecha cuenta cuantos camiones grandes hay registrados cuya fecha de adquisicion es posterior a dicha fecha
        int cantCamGrandesRegPostFecha(Fecha);
        //destructor
        ~Fachada();

};

#endif // FACHADA_H_INCLUDED
