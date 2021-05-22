#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"


static char juegosDescripcion[10][20]={
    "Yenga",
    "Tejo",
    "Mago",
    "Damas",
    "Ajedrez"
 };


static int codigo[5]={10,14,15,12,13};

static float importe[5]={500,800,600,700,400};

static int categoria[5]={1,4,5,1,3};

static char categoriaDescripcion[5][51]={
    "Mesa",
    "Azar",
    "Estrategia",
    "Salon",
    "Magia"
 };
//
static int categoriaId[5]={1,2,3,4,5};



static char localidadDescripcion[10][20]={
    "Avellaneda",
    "Banfield",
    "Quilmes",
    "Pergamino",
    "Junin"
 };


static int codigoLocalidad[5]={21,25,22,24,23};





 //Harcodeo juegos
int hardcodearJuegos(eJuego juegos[], int tam, int cant)
{
    int total=0;

    if (juegos != NULL && tam >0 && cant >=0 && cant <=tam)
    {

        for (int i=0; i<cant; i++)
        {

            strcpy(juegos[i].descripcion, juegosDescripcion[i]);
            juegos[i].codigo = codigo[i];
            juegos[i].importe=importe[i];
            juegos[i].idCategoria = categoria[i];
            total++;
        }
    }
    return total;
}


 //Harcodeo categorias
int hardcodearCategorias(eCategoria categoria[], int tamcat, int cant)
{
    int total=0;

    if (categoria != NULL && tamcat >0 && cant >=0 && cant <=tamcat)
    {

        for (int i=0; i<cant; i++)
        {

            strcpy(categoria[i].descripcion, categoriaDescripcion[i]);
            categoria[i].id = categoriaId[i];
            total++;
        }
    }
    return total;
}


 //Harcodeo localidades
int hardcodearLocalidades(eLocalidad localidad[], int taml, int cant)
{
    int total=0;

    if (localidad != NULL && taml >0 && cant >=0 && cant <=taml)
    {

        for (int i=0; i<cant; i++)
        {

            strcpy(localidad[i].descripcion, localidadDescripcion[i]);
            localidad[i].idLocalidad = codigoLocalidad[i];
            total++;
        }
    }
    return total;
}
