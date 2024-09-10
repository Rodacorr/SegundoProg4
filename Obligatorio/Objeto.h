#ifndef OBJETO_H_INCLUDED
#define OBJETO_H_INCLUDED
#include "Fecha.h"
class Objeto
{
    private:
    public:
            //selectora del tipo de objeto
            virtual String getTipoObjeto() = 0;
};

#endif // OBJETO_H_INCLUDED
