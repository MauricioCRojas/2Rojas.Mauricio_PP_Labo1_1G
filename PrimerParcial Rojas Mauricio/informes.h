#include "juegos.h"
#include "cliente.h"
#include "alquiler.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


int mostrarJuegosMesa (eJuego juegos[], int tam, eCategoria categoria[], int tamcat);

int mostrarAlquileresXCliente (eCliente clientes[], int tamc, eAlquiler alquiler[],
                               int tama, eJuego juegos[], int tam, eLocalidad localidad[], int taml);


int mostrarImportesXCliente (eCliente clientes[], int tamc, eAlquiler alquiler[],
                               int tama, eJuego juegos[], int tam, eLocalidad localidad[], int taml);



//Primer informe referido a localidad
int mostrarClientesAvellaneda (eCliente clientes[], int tama, eLocalidad localidad[], int taml);

//Segundo informe referido a localidad
int mostrarClientesQuilmes (eCliente clientes[], int tama, eLocalidad localidad[], int taml);


int mostrarClientesNoAlquilaron (eAlquiler alquiler[], int tama, eCliente clientes[], int tamc);

int mostrarRecaudacionPorFecha(eCliente clientes[], eAlquiler alquiler[], eJuego juegos[],int tama,int tamc, int tam);

//no llegue a documentar todo, profe

