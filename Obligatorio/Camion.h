#ifndef CAMION_H_INCLUDED
#define CAMION_H_INCLUDED
#include "Camionero.h"
class Camion : public Objeto
{
    private:
            String matricula;
            String marca;
            int cantViajesAnuales;
            Camionero * camionero;
    public:
            //constructor por defecto del camion
            Camion();
            //constructor comun del camion
            Camion(String,String,int,Camionero *);
            //constructor de copia del camion
            Camion(const Camion &);
            //selectora de la matricula del camion
            String getMatricula();
            //selectora de la marca del camion
            String getMarca();
            //selectora de la cantidad de viajes anuales del camion
            int getCantViajesAnuales();
            //selectora del  camionero del camion
            Camionero * getCamionero();
            //modificador de la matricula del camion
            void setMatricula(String);
            //modificador de la marca del camion
            void setMarca(String);
            //modificador de la cantidad de viajes anuales del camion
            void setCantViajesAnuales(int);
            //modificador del  camionero del camion
            void setCamionero(Camionero *);
            //retorna el tipo de objeto
            virtual String getTipoObjeto() = 0;
            //cantidad de metros cúbicos anuales que el camiones es capaz de transportar
            virtual float cantMetrosCub() = 0;
            //destructor del camion
            virtual ~Camion();
};
#endif // CAMION_H_INCLUDED
