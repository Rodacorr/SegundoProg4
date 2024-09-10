#ifndef SIMPLE_H_INCLUDED
#define SIMPLE_H_INCLUDED
#include "Camion.h"
class Simple : public Camion
{
    private:
        String depto;
    public:
        //constructor por defecto del camion simple
        Simple();
        //constructor comun del camion simple
        Simple(String,String,int,Camionero *,String);
        //constructor de copia del camion simple
        Simple(const Simple &);
        //selectora de departamento del camion simple
        String getDepto();
        //modificador de departamento del camion simple
        void setDepto(String);
        //retorna el tipo de objeto
        String getTipoObjeto();
        //cantidad de metros cúbicos anuales que el camion simple es capaz de transportar
        float cantMetrosCub();
};

#endif // SIMPLE_H_INCLUDED
