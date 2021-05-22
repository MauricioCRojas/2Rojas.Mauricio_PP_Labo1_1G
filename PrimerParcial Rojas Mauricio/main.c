#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"
#include "cliente.h"
#include "alquiler.h"
#include "juegos.h"
#include "informes.h"
#define TAM 5
#define TAMC 10
#define TAMA 10
#define TAMCAT 5
#define TAML 5



/** \brief Da de baja un cliente y si tiene, su alquiler
 * \param Estructura array clientes[]
 * \param tamc tamaño de vector clientes
 * \param Estructura array alquiler[]
 * \param tama tamaño de vector alquiler
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int bajaCliente (eCliente clientes[], int tamc, eAlquiler alquiler[], int tama, eLocalidad localidad[], int taml);
//Profe, tuve que dejar el prototipo aca y el desarrollo abajo del main-/, porque cuando
//lo dejaba en clientes.c y clientes.h, aunque agregue el #include alquiler.h
//me tiraba el error raro tipo deeply. Disculpe y gracias.

int main()
{
    eJuego juegos[TAM];
    eCliente clientes[TAMC];
    eAlquiler alquiler[TAMA];
    eCategoria categoria[TAMCAT];
    eLocalidad localidad[TAML];


    int nextId = 10;
    int nextIdAlq = 1;


    char seguir = 's';
    char seguir2= 's';
    char confirma;

    hardcodearJuegos(juegos, TAM, 5);
    hardcodearCategorias(categoria, TAMCAT, 5);
    hardcodearLocalidades(localidad, TAML, 5);
    inicializarClientes(clientes, TAMC);
    inicializarAlquiler(alquiler, TAMA);

    do
    {
        fflush(stdin);
        switch (menu())
        {
        case 1:
            if(altaCliente (clientes, TAMC, &nextId, localidad, TAML)==1)
            {
                printf("Alta exitosa\n");
            }
            else
            {
                printf("Hubo un problema en el alta del cliente\n");
            }

            break;
        case 2:
            fflush(stdin);
            if(modificarCliente(clientes, TAMC, localidad, TAML)==1)
            {
                printf("Modificacion exitosa\n");
            }
            else
            {
                printf("No se pudo completar la modificacion\n");
            }
            break;
        case 3:
            if(bajaCliente(clientes, TAMC, alquiler, TAMA, localidad, TAML)==1)
            {
                printf("Baja exitosa\n");
            }
            else
            {
                printf("No se pudo completar la baja\n");
            }
            break;
        case 4:
            if(ordenarClientes (clientes, TAMC)==1 && mostrarClientes(clientes, TAMC, localidad, TAML)==1)
            {
                printf("Se ordeno por apellido y nombre de manera correcta\n");
            }
            else
            {
                printf("No se puede mostrar los clientes ni ordenarlos\n\n");
            }
            break;
        case 5:
            if(altaAlquiler(alquiler, TAMA, &nextIdAlq, clientes, TAMC, juegos, TAM, localidad, TAML)==1)
            {
                printf("Alta exitosa\n");
            }
            else
            {
                printf("Hubo un problema en el alta del alquiler\n");
            }
            break;
        case 6:
            if(mostrarAlquileres(alquiler, TAMA, clientes, TAMC, juegos, TAM)==1)
            {
                printf("Se mostraron los alquileres correctamente\n");
            }
            else
            {
                printf("Hubo un problema al mostrar los alquileres\n");
            }
            break;
        case 7:
            do
            {
                fflush(stdin);
                switch(menuInformes())
                {
                case 1:
                    if(mostrarJuegosMesa (juegos, TAM, categoria, TAMCAT)==1)
                    {
                        printf("Se mostraron los juegos de mesa correctamente\n");
                    }
                    else
                    {
                        printf("Hubo un error al intentar mostrar los juegos de mesa\n");
                    }
                    system("pause");
                    break;
                case 2:
                    if(mostrarAlquileresXCliente (clientes, TAMC, alquiler,
                                                  TAMA, juegos, TAM, localidad, TAML)==1)
                    {
                        printf("Informe mostrado correctamente\n");

                    }
                    else
                    {
                        printf("Error al intentar mostrar informe\n");
                    }
                    system("pause");

                    break;
                case 3:
                    mostrarImportesXCliente(clientes, TAMC, alquiler,
                                            TAMA, juegos, TAM, localidad, TAML);
                    system("pause");

                    break;
                case 4:
                    mostrarClientesAvellaneda (clientes, TAMA, localidad, TAML);
                    system("pause");

                    break;
                case 5:
                    mostrarClientesQuilmes (clientes, TAMA, localidad, TAML);
                    system("pause");
                    break;
                case 6:
                    mostrarClientesNoAlquilaron (alquiler, TAMA, clientes, TAMC);
                    system("pause");

                    break;
                case 7:
                    if(mostrarRecaudacionPorFecha(clientes, alquiler, juegos,TAMA, TAMC,TAM))
                    {
                        printf("Informe mostrado correctamente\n");

                    }
                    else
                    {
                        printf("Error al intentar mostrar informe\n");
                    }
                    system("pause");
                    break;
                case 8:
                    break;
                case 12:
                    seguir2='n';
                    break;
                }
            }
            while(seguir2=='s');
            break;
        case 8:
            printf ("Seguro que quiere salir?: ");
            fflush (stdin);
            scanf ("%c", &confirma);
            if (confirma=='s')
            {
                seguir='n';
            }
            break;
        default:
            printf("Opcion invalida\n\n");

        }

        system ("pause");

    }
    while (seguir=='s');
    return 0;
}


//Baja cliente
int bajaCliente (eCliente clientes[], int tamc, eAlquiler alquiler[], int tama, eLocalidad localidad[], int taml)
{
    int todoOk=0;
    if(clientes!=NULL && tamc>0 && alquiler!=NULL && tama>0)
    {
        int indice;
        int codigo;
        char confirma;

        system("cls");

        printf("    Baja cliente\n\n");
        mostrarClientes(clientes, tamc, localidad, taml);
        printf("Ingrese codigo:");
        scanf("%d", &codigo);

        indice= buscarCliente(clientes, tamc, codigo);
        if (indice==-1)
        {
            printf("No existe un cliente con el codigo %d\n", codigo);
        }
        else
        {
            mostrarCliente(clientes[indice], localidad, taml);
            printf("Confirma baja?:");
            fflush(stdin);
            scanf("%c", &confirma);

            if (confirma=='s')
            {

                for (int i=0; i<tama; i++)
                {
                    if (alquiler[i].codCliente==clientes[indice].codigo)
                    {
                        alquiler[i].isEmpty=1;
                    }

                }
                clientes[indice].isEmpty=1;
                todoOk=1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }
    return todoOk;
}

