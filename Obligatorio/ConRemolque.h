#ifndef CONREMOLQUE_H_INCLUDED
#define CONREMOLQUE_H_INCLUDED
#include "Grande.h"
class ConRemolque : public Grande
{
    private:
        float capRemolque;
    public:
        //constructor por defecto del camion con remolque
        ConRemolque();
        //constructor comun del camion con remolque
        ConRemolque(String,String,int,Camionero *,float,Fecha,float);
        //constructor de copia del camion con remolque
        ConRemolque(const ConRemolque &);
        //selectora de la capacidad del camion con remolque
        float getCapRemolque();
        //modificador de la capacidad del camion con remolque
        void setCapRemolque(float);
        //retorna el tipo de objeto
        String getTipoObjeto();
        //cantidad de metros cúbicos anuales que el camion simple es capaz de transportar
        float cantMetrosCub();
        //destructor del camion con remolque
        ~ConRemolque();
};

#endif // CONREMOLQUE_H_INCLUDED
