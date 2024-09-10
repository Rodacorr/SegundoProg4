#include "tipoError.h"
void DesplegarError(int error)
{
    switch(error)
    {
    case 0:
        cout << "\nNo existe el camionero buscado.\n";
        break;
    case 1:
        cout << "\nYa existe un camion registrado con la misma matricula.\n";
             break;
    case 2:
        cout << "\nNo existen camiones registrados en el sistema.\n";
        break;
    case 3:
        cout << "\nNo existe el camion buscado.\n";
        break;
    case 4:
        cout << "\nYa existe un camionero registrado con dicha cedula.\n";
        break;
    case 5:
        cout << "\nNo existen camioneros registrados en el sistema.\n";
        break;
    case 6:
        cout << "\nEl camion no existe.\n";
        break;

    default:
        ;
    }
}

