#ifndef GRANDE_H_INCLUDED
#define GRANDE_H_INCLUDED
#include "Camion.h"
class Grande : public Camion
{
    private:
        float volumen;
        Fecha fechaAdquirido;
    public:
        //constructor por defecto del camion grande
        Grande();
        //constructor comun del camion grande
        Grande(String,String,int,Camionero *,float,Fecha);
        //constructor de copia del camion grande
        Grande(const Grande &);
        //selectora del volumen del camion grande
        float getVolumen();
        //selectora de la fecha adquirido del camion grande
        Fecha getFechaAdquirido();
        //modificador del volumen del camion grande
        void setVolumen(float);
        //modificador de la fecha adquirido del camion grande
        void setFechaAdquirido(Fecha);
        //retorna el tipo de objeto
        String getTipoObjeto();
        //cantidad de metros cúbicos anuales que el camion simple es capaz de transportar
        float cantMetrosCub();
        //destructor del camion grande
        ~Grande();
};

#endif // GRANDE_H_INCLUDED
