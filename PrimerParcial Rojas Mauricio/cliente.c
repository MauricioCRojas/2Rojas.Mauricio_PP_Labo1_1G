#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "alquiler.h"
#include "validaciones.h"

//Menu ABM
int menu ()
{
    int opcion;
    system("cls");
    printf ("Gestion de Alquiler Clientes\n\n");
    printf ("1- Alta Cliente\n");
    printf ("2- Modificar Cliente\n");
    printf ("3- Baja Cliente\n");
    printf ("4- Mostrar y Ordenar Clientes\n");
    printf ("5- Alta alquiler\n");
    printf ("6- Mostrar alquileres\n");
    printf ("7- Informes\n");
    printf ("8- Salir\n");
    printf ("Ingrese opcion: ");
    scanf ("%d", &opcion);

    return opcion;
}

//Menu Informes
int menuInformes ()
{
    int opcion;
    system("cls");
    printf ("Menu de informes\n\n");
    printf ("1- Informar Juegos de Mesa\n");
    printf ("2- Informar Alquiler/Alquileres segun cliente\n");
    printf ("3- Mostrar importes por cliente\n");
    printf ("4- Mostrar clientes de Avellaneda\n");
    printf ("5- Mostrar clientes de Quilmes\n");
    printf ("6- Mostrar clientes que no alquilaron\n");
    printf ("7- Importes de cierta fecha\n");
    printf ("8- xxxxxxxxxxxxxxxx\n");
    printf ("12- Salir\n");
    printf ("Ingrese opcion: ");
    scanf ("%d", &opcion);
    return opcion;
}


//Inializo isEmpty en 1
int inicializarClientes (eCliente clientes[], int tamc)
{
    int todoOk=0;
    if (clientes!=NULL && tamc >0)
    {
        for (int i=0; i<tamc; i++)
        {
            clientes[i].isEmpty=1;
        }
    }
    return todoOk;
}



//Alta cliente
int altaCliente (eCliente clientes[], int tamc, int* pId, eLocalidad localidad[], int taml)
{
    int todoOk=0;
    int indice;
    eCliente nuevoCliente;

    if (clientes != NULL && tamc > 0 && pId!= NULL)
    {
        system("cls");
        printf("       Alta cliente\n\n");
        printf("Id Cliente: %d\n", *pId);

        indice = buscarLibre(clientes, tamc);
        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            if(!getNombre(nuevoCliente.nombre,"Ingrese nombre: ","Error.\n",51,3)&&
                    !getNombre(nuevoCliente.apellido,"Ingrese apellido: ","Error.\n",51,3)&&
                    !getCaracter(&nuevoCliente.sexo,"Ingrese sexo: ","Error.\n",'f','m',3)&&
                    !getNumero(&nuevoCliente.telefono,"Ingrese telefono: ","Error.\n",0,1410065407,3)&&
                    mostrarLocalidades(localidad, taml) &&
                    !getNumero(&nuevoCliente.idLocalidad,"Ingrese Id localidad: ","Error.\n",20,25,3))
            {
                nuevoCliente.codigo=*pId;
                nuevoCliente.isEmpty=0;
                clientes[indice]=nuevoCliente;
                //actualizamos ID
                (*pId)++;
                todoOk=1;
            }
            else
            {
                printf("Error, no se pudo dar de alta al cliente.\n");
            }
        }

    }
    return todoOk;
}

//Buscar libre
int buscarLibre (eCliente clientes[], int tamc)
{
    int indice = -1;

    if (clientes != NULL && tamc > 0)
    {

        for (int i=0; i<tamc; i++)
        {
            if(clientes[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;

}







//Modificar cliente
int modificarCliente(eCliente clientes[], int tamc, eLocalidad localidad[], int taml)
{

    int todoOk=0;
    if (clientes!= NULL && tamc>0)
    {

        int indice=-1;
        int id;
        char confirma;
        char confirma2='s';
        eCliente auxCliente;
        int flagNombre=0;
        int flagApellido=0;
        int flagSexo=0;
        int flagTelefono=0;
        int flagLocalidad=0;


        system("cls");

        printf("    Modificar Cliente\n\n");
        mostrarClientes(clientes, tamc, localidad, taml);
        printf("Ingrese id:");
        scanf("%d", &id);

        indice= buscarCliente(clientes, tamc, id);

        if (indice==-1)
        {
            printf("No existe un cliente con el id %d\n", id);
        }
        else
        {
            mostrarCliente(clientes[indice], localidad, taml);

            do
            {
                switch(menuModificaciones())
                {
                case 1:
                    mostrarCliente(clientes[indice], localidad, taml);
                    getNombre(auxCliente.nombre, "Ingrese nuevo nombre: ", "Error\n", 51, 3);
                    flagNombre=1;
                    break;
                case 2:
                    mostrarCliente(clientes[indice], localidad, taml);
                    getNombre(auxCliente.apellido, "Ingrese nuevo apellido: ", "Error\n", 51, 3);
                    flagApellido=1;
                    break;
                case 3:
                    mostrarCliente(clientes[indice], localidad, taml);
                    getCaracter(&auxCliente.sexo,"Ingre nuevo sexo: ", "Error\n", 'f','m',3);
                    flagSexo=1;
                    break;
                case 4:
                    mostrarCliente(clientes[indice], localidad, taml);
                    getNumero(&auxCliente.telefono,"Ingrese nuevo telefono: ","Error.\n",0,1410065407,3);
                    flagTelefono=1;
                    break;
                case 5:
                    mostrarCliente(clientes[indice], localidad, taml);
                    mostrarLocalidades(localidad, taml);
                    getNumero(&auxCliente.idLocalidad,"Ingrese nuevo Id localidad: ","Error.\n",20,25,3);
                    flagLocalidad=1;
                    break;
                case 6:
                    confirma2='n';
                    break;
                default:
                    printf("Opcion invalida\n");

                }
            }
            while(confirma2== 's');

            printf("Confirma modificacion?:");
            fflush(stdin);
            scanf("%c", &confirma);

            if (confirma=='s')
            {
                if(flagNombre==1)
                {
                    strcpy(clientes[indice].nombre, auxCliente.nombre);
                    flagNombre=0;
                }
                if (flagApellido==1)
                {
                    strcpy(clientes[indice].apellido, auxCliente.apellido);
                    flagApellido=0;
                }
                if (flagSexo==1)
                {
                    clientes[indice].sexo = auxCliente.sexo;
                    flagSexo=0;
                }
                if (flagTelefono==1)
                {
                    clientes[indice].telefono = auxCliente.telefono;
                    flagTelefono=0;
                }
                if (flagLocalidad==1)
                {
                    clientes[indice].idLocalidad = auxCliente.idLocalidad;
                    flagLocalidad=0;
                }
                todoOk=1;
                printf("Modificacion exitosa\n");
            }
            else
            {
                printf("Modificacion cancelada por el usuario\n");
            }
        }
    }
    return todoOk;
}


//Mostrar cliente (uno)
void mostrarCliente (eCliente unCliente, eLocalidad localidad[], int taml)
{
    char descripcion[20];

    cargarDescripcionLocalidad(unCliente.idLocalidad, localidad, taml, descripcion);

    printf("%10s   %10s             %c        %d         %10s         %d\n",
           unCliente.nombre,
           unCliente.apellido,
           unCliente.sexo,
           unCliente.telefono,
           descripcion,
           unCliente.codigo);

}


//Mostrar clientes (todos)
int mostrarClientes(eCliente clientes[], int tamc, eLocalidad localidad[], int taml)
{
    int todoOk=0;
    if(clientes!=NULL && tamc>0)
    {

        int flagClientes=0;
        if(clientes!=NULL && tamc>0)
        {
            printf("      LISTA DE CLIENTES\n");
            printf("  Nombre         Apellido         Sexo      Telefono       Localidad       CodigoCliente\n");

            for(int i=0; i<tamc; i++)
            {
                if(clientes[i].isEmpty==0)
                {
                    mostrarCliente(clientes[i], localidad, taml);
                    flagClientes=1;
                    todoOk=1;
                }
            }
            if(flagClientes==0)
            {
                printf("No hay clientes cargados por el momento\n");
            }
            printf("\n");
        }
    }
    return todoOk;
}


//Menu modificaciones
int menuModificaciones ()
{
    int opcion;
    system("cls");
    printf ("Modificacion de clientes\n\n");
    printf ("1- Modificar nombre\n");
    printf ("2- Modificar apellido\n");
    printf ("3- Modificar sexo\n");
    printf ("4- Modificar telefono\n");
    printf ("5- Modificar localidad\n");
    printf ("6- Salir y guardar/cancelar\n");
    printf ("Ingrese opcion: ");
    scanf ("%d", &opcion);

    return opcion;
}

//Buscar cliente
int buscarCliente (eCliente clientes[], int tamc, int id)
{
    int indice = -1;

    if (clientes != NULL && tamc > 0)
    {

        for (int i=0; i<tamc; i++)
        {
            if(clientes[i].isEmpty==0 && clientes[i].codigo==id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;

}





//Ordenamiento clientes
int ordenarClientes (eCliente clientes[], int tamc)
{
    int todoOk=0;
    if (clientes != NULL && tamc > 0)
    {
        eCliente auxStruct;
        for (int i=0; i < tamc-1 ; i++)
        {
            if(clientes[i].isEmpty==0)
            {
                for (int j=i+1 ; j < tamc; j++)
                {
                    if(strcmp(clientes[i].apellido, clientes[j].apellido)>0 ||
                            (strcmp(clientes[i].apellido, clientes[j].apellido)==0 && strcmp(clientes[i].nombre, clientes[j].nombre)>0))
                    {
                        auxStruct=clientes[i];
                        clientes[i]=clientes[j];
                        clientes[j]=auxStruct;
                    }
                }
                todoOk=1;
            }

        }
    }
    return todoOk;
}


//Cargar descripcion cliente
int cargarDescripcionCliente(int id, eCliente clientes[], int tamc, char descripcion[])
{
    int todoOk=0;
    if (id>=10 && id <=20 && clientes != NULL && tamc >0 && descripcion!=NULL)
    {
        for(int i=0; i<tamc; i++)
        {
            if(clientes[i].codigo== id)
            {
                strcpy(descripcion, clientes[i].nombre);
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}




//Mostrar localidad (uno)
void mostrarLocalidad (eLocalidad unaLocalidad)
{

    printf("    %d                  %10s\n",
           unaLocalidad.idLocalidad,
           unaLocalidad.descripcion);

}


//Mostrar localidades (todos)
int mostrarLocalidades(eLocalidad localidad[], int taml)
{
    int todoOk=0;
    if(localidad!=NULL && taml>0)
    {

        int flagLocalidad=0;
        if(localidad!=NULL && taml>0)
        {
            printf("      LISTA DE LOCALIDADES\n");
            printf("IdLocalidad           NombreLocalidad\n");

            for(int i=0; i<taml; i++)
            {
                mostrarLocalidad(localidad[i]);
                flagLocalidad=1;
                todoOk=1;

            }
            if(flagLocalidad==0)
            {
                printf("No hay localidades cargados por el momento\n");
            }
            printf("\n");
        }
    }
    return todoOk;
}


//Cargar descripcion localidad
int cargarDescripcionLocalidad(int id, eLocalidad localidad[], int taml, char descripcion[])
{
    int todoOk=0;
    if (id>=20 && id <=25 && localidad != NULL && taml >0 && descripcion!=NULL)
    {
        for(int i=0; i<taml; i++)
        {
            if(localidad[i].idLocalidad== id)
            {
                strcpy(descripcion, localidad[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}
