#include "Fachada.h"
#include "tipoError.h"
int main()
{
    Fachada fachada;
    int op = -1;
    do
    {
        printf("Sistema de Gestion del Gremio de Camioneros Tatuados\n\n");
        printf("\n1-Registrar nuevo camion en el sistema.");
        printf("\n2-Listado basico de todos los camiones registrados.");
        printf("\n3-Listado detallado de un camion dado su matricula.");
        printf("\n4-Registrar nuevo camionero en el sistema.");
        printf("\n5-Listado de todos los camioneros registrados.");
        printf("\n6-Cantidad total de metros cubicos que transporta toda la flota de camiones.");
        printf("\n7-Modificar cantidad de viajes anuales de un camion dada su matricula.");
        printf("\n8-Cantidad de cada tipo de camion registrado.");
        printf("\n9-Listar datos de camionero con mayor cantidad de tatuajes.");
        printf("\n10-Cantidad de camiones con fecha de adquisicion posterior a fecha dada.");
        printf("\n0-Salir");
        printf("\nIngrese opcion: ");
        fflush(stdin);
        scanf("%d",&op);
        switch(op)
        {
        case 1:
        {
            int error = -1;
            int cantViajes = 0;
            long int cedula = 0;
            int tipoCamion = 0;
            String matricula;
            String marca;
            printf("\nIngrese matricula: ");
            fflush(stdin);
            matricula.scan();
            printf("\nIngrese marca: ");
            fflush(stdin);
            marca.scan();
            printf("\nIngrese cantidad de viajes Anuales: ");
            fflush(stdin);
            scanf("%d",&cantViajes);
            printf("\nIngrese cedula del camionero que lo conduce: ");
            fflush(stdin);
            scanf("%ld",&cedula);
            Camionero * camionero = new Camionero();
            do
            {
                printf("\nIngrese tipo de camion: ");
                printf("\n1-Simple");
                printf("\n2-Grande");
                printf("\n3-Con remolque");
                printf("\nIngrese opcion: ");
                fflush(stdin);
                scanf("%d",&tipoCamion);
                switch(tipoCamion)
                {
                case 1:
                {
                    String departamento;
                    printf("\nIngrese departamento: ");
                    fflush(stdin);
                    departamento.scan();
                    Simple * simple = new Simple(matricula,marca,cantViajes,camionero,departamento);
                    fachada.registrarCamion(simple,cedula,error);
                    DesplegarError(error);
                }
                break;
                case 2:
                {
                    float volumen = 0;
                    int dia = 0, mes = 0, anio = 0;
                    printf("\nIngrese volumen: ");
                    fflush(stdin);
                    scanf("%f",&volumen);
                    printf("\nIngrese fecha de adquirido: \n");
                    printf("\nDia: ");
                    fflush(stdin);
                    scanf("%d",&dia);
                    printf("\nMes: ");
                    fflush(stdin);
                    scanf("%d",&mes);
                    printf("\nAnio: ");
                    fflush(stdin);
                    scanf("%d",&anio);
                    Fecha date(dia,mes,anio);
                    Grande * grande = new Grande(matricula,marca,cantViajes,camionero,volumen,date);
                    fachada.registrarCamion(grande,cedula,error);
                    DesplegarError(error);
                }
                break;
                case 3:
                {
                    float volumen = 0, capacidad = 0;
                    int dia = 0, mes = 0, anio = 0;
                    printf("\nIngrese volumen: ");
                    fflush(stdin);
                    scanf("%f",&volumen);
                    printf("\nIngrese fecha de adquirido: \n");
                    printf("\nDia: ");
                    fflush(stdin);
                    scanf("%d",&dia);
                    printf("\nMes: ");
                    fflush(stdin);
                    scanf("%d",&mes);
                    printf("\nAnio: ");
                    fflush(stdin);
                    scanf("%d",&anio);
                    Fecha date(dia,mes,anio);
                    printf("\nIngrese capacidad: ");
                    fflush(stdin);
                    scanf("%f",&capacidad);
                    ConRemolque * remolque = new ConRemolque(matricula,marca,cantViajes,camionero,volumen,date,capacidad);
                    fachada.registrarCamion(remolque,cedula,error);
                    DesplegarError(error);
                }
                break;
                default:
                {
                    printf("\nIngrese una opcion valida\n");
                }
                break;
                }
            }
            while((tipoCamion!=1)&&(tipoCamion!=2)&&(tipoCamion!=3));
        }
        break;
        case 2:
        {
            Iterador iter = fachada.listarCamiones();
            while(iter.hayMasObjetos())
            {
                Objeto * obj = iter.siguienteObjeto();
                if((obj->getTipoObjeto()=="Simple")||(obj->getTipoObjeto()=="Grande")||(obj->getTipoObjeto()=="ConRemolque"))
                {
                    String matricula = ((Camion *) obj)->getMatricula();
                    String marca = ((Camion *) obj)->getMarca();
                    int cantViajes = ((Camion *) obj)->getCantViajesAnuales();
                    String tipoCamion = ((Camion *) obj)->getTipoObjeto();
                    printf("\nMatricula: ");
                    matricula.print();
                    printf(" - Marca: ");
                    marca.print();
                    printf(" - Cantidad viajes anuales: %d",cantViajes);
                    printf(" - Tipo: ");
                    tipoCamion.print();
                    printf("\n");
                }
            }
        }
        break;
        case 3:
        {
            int error = -1;
            String enrollment;
            printf("\nIngrese matricula: ");
            fflush(stdin);
            enrollment.scan();
            Camion * cam;
            fachada.datosCamionXMatricula(enrollment,cam,error);
            if(error == -1)
            {
                String matricula = cam->getMatricula();
                String marca = cam->getMarca();
                int cantViajes = cam->getCantViajesAnuales();
                String tipoCamion = cam->getTipoObjeto();
                printf("\nMatricula: ");
                matricula.print();
                printf(" - Marca: ");
                marca.print();
                printf(" - Cantidad viajes anuales: %d",cantViajes);
                printf(" - Tipo: ");
                tipoCamion.print();
                if(tipoCamion == "Simple")
                {
                    String depto = ((Simple *) cam)->getDepto();
                    printf(" - Departamento: ");
                    depto.print();
                    printf("\n");
                }
                else
                {
                    if(tipoCamion == "Grande")
                    {
                        float volumen = ((Grande *) cam)->getVolumen();
                        printf(" - Volumen: %f",volumen);
                        Fecha adq = ((Grande *) cam)->getFechaAdquirido();
                        printf(" - Fecha de Adquirido: %d/%d/%d\n",adq.getDia(),adq.getMes(),adq.getAnio());
                    }
                    else
                    {
                        float volumen = ((ConRemolque *) cam)->getVolumen();
                        float capacidad = ((ConRemolque *) cam)->getCapRemolque();
                        printf(" - Volumen: %f",volumen);
                        Fecha adq = ((ConRemolque *) cam)->getFechaAdquirido();
                        printf(" - Fecha de Adquirido: %d/%d/%d",adq.getDia(),adq.getMes(),adq.getAnio());
                        printf(" - Capacidad: %f\n",capacidad);
                    }
                }
                Camionero * camionero = cam->getCamionero();
                printf("Camionero: ");
                printf("\nCedula: %ld - ",camionero->getCedula());
                printf("Nombre: ");
                camionero->getNombre().print();
                printf(" - Cantidad de tatuajes: %ld - ",camionero->getCantTatuajes());
                Fecha date = camionero->getFechaNacimiento();
                printf("Fecha de Nacimiento: %d/%d/%d\n",date.getDia(),date.getMes(),date.getAnio());
            }
            else
            {
                DesplegarError(error);
            }
        }
        break;
        case 4:
        {
            int error = -1;
            long int cedula = 0;
            String nombre;
            int cantTatuajes = 0, dia = 0, mes = 0, anio = 0;
            printf("\nIngrese cedula del camionero: ");
            fflush(stdin);
            scanf("%ld",&cedula);
            printf("\nIngrese nombre del camionero: ");
            fflush(stdin);
            nombre.scan();
            printf("\nIngrese cantidad de tatuajes del camionero: ");
            fflush(stdin);
            scanf("%d",&cantTatuajes);
            printf("\nIngrese fecha de nacimiento: ");
            printf("\nDia: ");
            fflush(stdin);
            scanf("%d",&dia);
            printf("\nMes: ");
            fflush(stdin);
            scanf("%d",&mes);
            printf("\nAnio: ");
            fflush(stdin);
            scanf("%d",&anio);
            Fecha date(dia,mes,anio);
            Camionero * cam = new Camionero(cedula,nombre,cantTatuajes,date);
            fachada.registrarCamionero(cam,error);
            DesplegarError(error);
        }
        break;
        case 5:
        {
            Iterador iter = fachada.listarCamioneros();
            while(iter.hayMasObjetos())
            {
                Objeto * obj = iter.siguienteObjeto();
                long int cedula = ((Camionero *) obj)->getCedula();
                String nombre = ((Camionero *) obj)->getNombre();
                int cantTattoo = ((Camionero *) obj)->getCantTatuajes();
                Fecha date = ((Camionero * ) obj)->getFechaNacimiento();
                printf("\nCedula: %ld - ",cedula);
                printf("Nombre: ");
                nombre.print();
                printf(" - Cantidad de tatuajes: %ld - ",cantTattoo);
                printf("Fecha de Nacimiento: %d/%d/%d\n",date.getDia(),date.getMes(),date.getAnio());
            }
        }
        break;
        case 6:
        {
            float total = fachada.sumaTotalMetrosCub();
            printf("\nCantidad Total: %f\n",total);
        }
        break;
        case 7:
        {
            int error = -1;
            String enrollment;
            int x = 0;
            printf("\nIngrese matricula: ");
            fflush(stdin);
            enrollment.scan();
            printf("\nIngrese cantidad de viajes anuales: ");
            fflush(stdin);
            scanf("%d",&x);
            fachada.setCantViajesAnualesXMatricula(enrollment,x,error);
            DesplegarError(error);
        }
        break;
        case 8:
        {
            int simple = 0, grande = 0, conRemolque = 0;
            fachada.cantTiposCamiones(simple,grande,conRemolque);
            printf("\nSimples: %d",simple);
            printf("\nGrandes: %d",grande);
            printf("\nCon remolque: %d\n",conRemolque);
        }
        break;
        case 9:
        {
            int error = -1;
            Camionero * cam = new Camionero();
            fachada.camioneroConMasTatuajes(cam,error);
            if(error == -1)
            {
                printf("\nCedula: %ld",cam->getCedula());
                printf(" - Nombre: ");
                cam->getNombre().print();
                printf(" - Cantidad de tatuajes: %d",cam->getCantTatuajes());
                Fecha date = cam->getFechaNacimiento();
                printf(" - Fecha de Nacimiento: %d/%d/%d\n",date.getDia(),date.getMes(),date.getAnio());
            }
            else
            {
                DesplegarError(error);
            }
        }
        break;
        case 10:
        {
            int dia = 0, mes = 0, anio = 0;
            printf("\nDia: ");
            fflush(stdin);
            scanf("%d",&dia);
            printf("\nMes: ");
            fflush(stdin);
            scanf("%d",&mes);
            printf("\nAnio: ");
            fflush(stdin);
            scanf("%d",&anio);
            Fecha date(dia,mes,anio);
            int total = fachada.cantCamGrandesRegPostFecha(date);
            printf("Cantidad total: %d\n",total);
        }
        break;
        case 0:
        {
            printf("\nHasta la vista baby.\n");
        }
        break;
        default:
        {
            printf("\nIngrese una opcion valida\n");
        }
        break;
        }
    }
    while(op!=0);
}
