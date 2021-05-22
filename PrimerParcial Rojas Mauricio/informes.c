#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "informes.h"
#include "juegos.h"
#include "cliente.h"
#include "alquiler.h"


//1
int mostrarJuegosMesa (eJuego juegos[], int tam, eCategoria categoria[], int tamcat){
int todoOk=0;
if (juegos!=NULL && tam>0 && categoria!=NULL && tamcat>0){
int contJuegosMesa=0;
    for(int i=0; i<tam; i++){
        todoOk=1;
        if (categoria[0].id==juegos[i].idCategoria){
            contJuegosMesa++;
            printf("%10s\n", juegos[i].descripcion);
        }
    }
    printf("La cantidad de juegos de mesa es: %d\n", contJuegosMesa);
}
return todoOk;
}


//2
int mostrarAlquileresXCliente (eCliente clientes[], int tamc, eAlquiler alquiler[],
                               int tama, eJuego juegos[], int tam, eLocalidad localidad[], int taml)
{
    int todoOk=0;
    if(clientes!=NULL && tamc>0 && alquiler!=NULL && tama>0 && juegos !=NULL && tam>0 && localidad !=NULL && taml>0){
            todoOk=1;
    int idCliente;
    int flag=0;
    printf("         Alquileres Clientes\n\n");

    mostrarClientes (clientes, tamc, localidad, taml);
    printf("Ingrese idCliente: ");
    scanf("%d", &idCliente);

    while(buscarCliente(clientes, tamc, idCliente)==-1)
    {
        printf("Id invalido. Reingrese idCliente: ");
        scanf("%d", &idCliente);

    }

    for (int i=0; i<tama; i++)
    {
        if(alquiler[i].codCliente==idCliente && alquiler[i].isEmpty==0)
        {
            mostrarAlquileres(alquiler, tama, clientes,tamc, juegos, tam);
            flag=1;
            break;
        }

    }
    if(flag==0)
    {
        printf("El cliente de idCliente %d no registra alquiler\n", idCliente);
    }
    }
    return todoOk;
}


//3
int mostrarImportesXCliente (eCliente clientes[], int tamc, eAlquiler alquiler[],
                               int tama, eJuego juegos[], int tam, eLocalidad localidad[], int taml)
{
    int todoOk=0;
    if(clientes!=NULL && tamc>0 && alquiler!=NULL && tama>0 && juegos !=NULL && tam>0 && localidad !=NULL && taml>0){
    todoOk=1;
    float importeTotal=0;
    int idCliente;
    int flag=0;
    printf("         Importes Clientes\n\n");

    mostrarClientes (clientes, tamc, localidad, taml);
    printf("Ingrese idCliente: ");
    scanf("%d", &idCliente);

    while(buscarCliente(clientes, tamc, idCliente)==-1)
    {
        printf("Id invalido. Reingrese idCliente: ");
        scanf("%d", &idCliente);

    }

    for (int i=0; i<tama; i++)
    {
        if(alquiler[i].codCliente==idCliente && alquiler[i].isEmpty==0)
        {
            importeTotal+= juegos[i].importe;
            mostrarAlquileres(alquiler, tama, clientes,tamc, juegos, tam);
            flag=1;
            //break;
            //saque el break y por eso me muestra el listado varias veces, pero sino no me sumaba cada importe
        }

    }
    if(flag==0)
    {
        printf("El cliente de idCliente %d no registra alquiler\n", idCliente);
    }
    else{
        printf("El importe total de este cliente es de %.2f\n", importeTotal);
    }
    }
    return todoOk;
}







//Muestra clientes de Avellaneda
int mostrarClientesAvellaneda (eCliente clientes[], int tama, eLocalidad localidad[], int taml){
int todoOk=0;
if (clientes!=NULL && tama>0 && localidad!=NULL && taml>0){
int contClientLocald=0;
    for(int i=0; i<tama; i++){
        todoOk=1;
        if (localidad[0].idLocalidad==clientes[i].idLocalidad){
            contClientLocald++;
            printf("%10s\n", clientes[i].nombre);
        }
    }
    printf("La cantidad de clientes de Avellaneda es: %d\n", contClientLocald);
}
return todoOk;
}


//Muestra clientes de Quilmes
int mostrarClientesQuilmes (eCliente clientes[], int tama, eLocalidad localidad[], int taml){
int todoOk=0;
if (clientes!=NULL && tama>0 && localidad!=NULL && taml>0){
int contClientLocald=0;
    for(int i=0; i<tama; i++){
        todoOk=1;
        if (localidad[2].idLocalidad==clientes[i].idLocalidad){
            contClientLocald++;
            printf("%10s\n", clientes[i].nombre);
        }
    }
    printf("La cantidad de clientes de Quilmes es: %d\n", contClientLocald);
}
return todoOk;
}


//4
int mostrarClientesNoAlquilaron (eAlquiler alquiler[], int tama, eCliente clientes[], int tamc){
int todoOk=0;
if (alquiler!=NULL && tama>0 && clientes!=NULL && tamc>0){
int contNoAlquilaron=0;
    for(int i=0; i<tama; i++){
        todoOk=1;
        for(int j=0; j<tamc; j++){
        if (clientes[i].codigo==alquiler[j].codCliente && alquiler[j].isEmpty==1){

            contNoAlquilaron++;
            printf("%10s\n", clientes[i].nombre);
        break;
        }
    }
    }
    printf("La cantidad de clientes que no alquilaron es: %d\n", contNoAlquilaron);
}
return todoOk;
}

//10
int mostrarRecaudacionPorFecha(eCliente clientes[], eAlquiler alquiler[], eJuego juegos[],int tama,int tamc, int tam) {
    int todoOk = 0;
    float auxImporte = 0;
    eFecha auxFecha;

    if(clientes!=NULL && tamc>0 && alquiler!=NULL && tama>0 && juegos !=NULL && tam>0){

    getNumero(&auxFecha.dia,"Ingrese dia de alquiler 1 a 31: ","Error.\n",1,31,3);
    getNumero(&auxFecha.mes,"Ingrese mes de alquiler 1 a 12: ","Error.\n",1,12,3);
    getNumero(&auxFecha.anio,"Ingrese anio de alquiler: ","Error.\n",2020,2021,3);


        for(int i = 0; i< tama; i++) {
            if(alquiler[i].fechaAlquiler.dia == auxFecha.dia &&
               alquiler[i].fechaAlquiler.mes == auxFecha.mes &&
               alquiler[i].fechaAlquiler.anio == auxFecha.anio)
                {
                    for(int j = 0; j<tam ; j++) {
                        if(juegos[j].codigo == alquiler[i].codJuego && alquiler[i].isEmpty == 0) {
                            auxImporte += juegos[j].importe;
                            todoOk = 1;
                        }
                    }
                }
        }

        printf("La recaudacion de la fecha %d/%d/%d fue de %.2f \n", auxFecha.dia, auxFecha.mes, auxFecha.anio, auxImporte);
    }

    return todoOk;
}

