#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juegos.h"


int cargarPrecioJuego(int idJuego, eJuego juegos[], int tam, float* precioJuego){
int todoOk=0;

if(idJuego>=10 && idJuego<=15 && juegos!=NULL && tam>0){
    for(int i=0; i<tam; i++){
        if(juegos[i].codigo==idJuego){
            *precioJuego=juegos[i].importe;
            todoOk=1;
            break;
        }
        }
    }

return todoOk;
}



int mostrarJuegos (eJuego juegos[], int tam)
{
    int todoOk=0;
    int flagJuegos=0;
    if(juegos!=NULL && tam>0)
    {
    printf("Lista de juegos:\n");
    printf("CodigoJuego     Descripcion         Importe    Id Categoria\n");
    for(int i=0; i<tam; i++)
        {
                mostrarJuego(juegos[i]);
                flagJuegos=1;
                todoOk=1;
        }
        if(flagJuegos==0)
        {
            printf("No hay juegos cargados por el momento\n");
        }
        printf("\n");
    }
    return todoOk;
}

void mostrarJuego(eJuego unJuego){

    printf("%d           %10s             %.2f      %d\n", unJuego.codigo, unJuego.descripcion, unJuego.importe, unJuego.idCategoria);

}


int cargarDescripcionJuego(int id, eJuego juegos[], int tam, char descripcion[]){
int todoOk=0;
if (id>=10 && id <=15 && juegos != NULL && tam >0 && descripcion!=NULL){
    for(int i=0; i<tam; i++){
        if(juegos[i].codigo== id){
            strcpy(descripcion, juegos[i].descripcion);
            todoOk=1;
            break;
        }
    }
}
return todoOk;
}
