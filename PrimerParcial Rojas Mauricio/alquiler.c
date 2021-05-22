#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alquiler.h"
#include "cliente.h"
#include "juegos.h"
#include "validaciones.h"

//Alta cliente
int altaAlquiler (eAlquiler alquiler[], int tama, int* pId, eCliente clientes[], int tamc, eJuego juegos[], int tam, eLocalidad localidad[], int taml)
{

    int todoOk=0;
    int indice;
    eAlquiler nuevoAlquiler;


    if (alquiler != NULL && tama > 0 && pId!= NULL && clientes != NULL && tamc > 0 && juegos!=NULL && tam>0)
    {
        system("cls");
        printf("       Alta alquiler\n\n");
        printf("Id Alquiler: %d\n", *pId);

        indice = buscarLibreAlquiler(alquiler, tama);
        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            if(mostrarClientes(clientes, tamc, localidad, taml) && !getNumero(&nuevoAlquiler.codCliente,"Ingrese codigo de cliente: ","Error.\n",10,30,3)&&
                    mostrarJuegos(juegos, tam) && !getNumero(&nuevoAlquiler.codJuego,"Ingrese codigo de juego: ","Error.\n",10,15,3)&&
                    !getNumero(&nuevoAlquiler.fechaAlquiler.dia,"Ingrese dia de alquiler 1 a 31: ","Error.\n",1,31,3)&&
                    !getNumero(&nuevoAlquiler.fechaAlquiler.mes,"Ingrese mes de alquiler 1 a 12: ","Error.\n",1,12,3)&&
                    !getNumero(&nuevoAlquiler.fechaAlquiler.anio,"Ingrese anio de alquiler: ","Error.\n",2020,2021,3))
            {
            nuevoAlquiler.codAlq=*pId;
            nuevoAlquiler.isEmpty=0;
            alquiler[indice]=nuevoAlquiler;
            //actualizamos ID
            (*pId)++;
            todoOk=1;

            }
        }
    }

    return todoOk;
}


//Buscar libre
int buscarLibreAlquiler (eAlquiler alquiler[], int tama)
{
    int indice = -1;

    if (alquiler != NULL && tama > 0)
    {

        for (int i=0; i<tama; i++)
        {
            if(alquiler[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;

}

//Inializo isEmpty en 1
int inicializarAlquiler (eAlquiler alquiler[], int tama)
{
    int todoOk=0;
       if (alquiler != NULL && tama > 0)
    {
        todoOk=1;
    for (int i=0; i<tama; i++)
    {
        alquiler[i].isEmpty=1;
    }
    }
    return todoOk;
}


int mostrarAlquileres (eAlquiler alquiler[], int tama, eCliente clientes[], int tamc, eJuego juegos[], int tam)
{
    int todoOk=0;
    int flag=0;
    if(alquiler!=NULL && tama>0 && clientes !=NULL && tamc>0 && juegos!=NULL && tam>0)
    {
        printf("Lista de alquileres:\n");
        printf(" CodigoAlquiler      NombreCliente      NombreJuego      Importe      FechaAlquiler\n");

        for(int i=0; i<tama; i++)
        {
            if(alquiler[i].isEmpty==0)
            {
                todoOk=1;
                mostrarAlquiler(alquiler[i], clientes, tamc, juegos, tam);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No hay alquileres cargados por el momento\n");
        }
        printf("\n");
    }
    return todoOk;

}

void mostrarAlquiler(eAlquiler unAlquiler, eCliente clientes[], int tamc, eJuego juegos[], int tam)
{
    if(clientes !=NULL && tamc>0 && juegos!=NULL && tam>0)
    {
    char descripcion[20];
    char descripcion2[20];
    float precioJuego;

    cargarDescripcionCliente(unAlquiler.codCliente, clientes, tamc, descripcion);
    cargarDescripcionJuego(unAlquiler.codJuego, juegos, tam, descripcion2);
    cargarPrecioJuego(unAlquiler.codJuego, juegos, tam, &precioJuego);

    printf("    %d                %10s      %10s           %.2f      %d/%d/%d\n", unAlquiler.codAlq, descripcion,
           descripcion2, precioJuego, unAlquiler.fechaAlquiler.dia, unAlquiler.fechaAlquiler.mes, unAlquiler.fechaAlquiler.anio);
    }
}

