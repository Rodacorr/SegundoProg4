#ifndef CAMIONERO_H_INCLUDED
#define CAMIONERO_H_INCLUDED
#include "Objeto.h"
class Camionero : public Objeto
{
    private:
            long int cedula;
            String nombre;
            int cantTatuajes;
            Fecha fechaNacimiento;
    public:
    //constructor por defecto del camionero
    Camionero();
    //constructor común del camionero
    Camionero(long int,String,int,Fecha);
    //constructor de copia del camionero
    Camionero(const Camionero &);
    //selectora cedula del camionero
    long int getCedula();
    //selectora nombre del camionero
    String getNombre();
    //selectora cantidad tatuajes del camionero
    int getCantTatuajes();
    //selectora fecha de nacimiento del camionero
    Fecha getFechaNacimiento();
    //modificador cedula del camionero
    void setCedula(long int);
    //modificador nombre del camionero
    void setNombre(String);
    //modificador cantidad tatuajes del camionero
    void setCantTatuajes(int);
    //modificador fecha de nacimiento del camionero
    void setFechaNacimiento(Fecha);
    //retorna el tipo de objeto
    String getTipoObjeto();
    //destructor del camionero
    ~Camionero();
};

#endif // CAMIONERO_H_INCLUDED
