#include "juegos.h"
#include "cliente.h"
#include "alquiler.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#endif // INFORMES_H_INCLUDED

/** \brief Busca ID y valida
 * \param Id introducido
 * \param eJuego juegos[], array de juegos
 * \param tam, tamanio del array de juego
 * \return retorna 1 si lo encuentra, 0 si no
 */
int validarJuego(int id, eJuego juegos[], int tam);


/** \brief Muestra juegos de mesa
 * \param eJuego juegos[], array de juegos
 * \param tam, tamanio del array de juego
 * \param eCategoria categoria[], array de categorias
 * \param tamcat, tamanio del array de categorias
 * \return retorna 1 si hay juegos de mesa, 0 si no
 */
int mostrarJuegosMesa (eJuego juegos[], int tam, eCategoria categoria[], int tamcat);


/** \brief Muestra los alquileres que realizo el cliente del Id ingresado
 * \param eCliente clientes[], array de clientes
 * \param tamc, tamanio del array de clientes
 * \param eAlquiler alquiler[], array de alquileres
 * \param tama, tamanio del array de alquileres
 * \param eJuego juegos[], array de juegos
 * \param tam, tamanio del array de juego
 * \param eLocalidad localidad[], array de localidades
 * \param taml, tamanio del array de localidades
 * \return retorna 1 si encuentra el cliente, 0 si no
 */
int mostrarAlquileresXCliente (eCliente clientes[], int tamc, eAlquiler alquiler[],
                               int tama, eJuego juegos[], int tam, eLocalidad localidad[], int taml);


/** \brief Muestra los importes que realizo el cliente del Id ingresado
 * \param eCliente clientes[], array de clientes
 * \param tamc, tamanio del array de clientes
 * \param eAlquiler alquiler[], array de alquileres
 * \param tama, tamanio del array de alquileres
 * \param eJuego juegos[], array de juegos
 * \param tam, tamanio del array de juego
 * \param eLocalidad localidad[], array de localidades
 * \param taml, tamanio del array de localidades
 * \return retorna 1 si encuentra el cliente, 0 si no
 */
int mostrarImportesXCliente (eCliente clientes[], int tamc, eAlquiler alquiler[],
                             int tama, eJuego juegos[], int tam, eLocalidad localidad[], int taml);



//Primer informe referido a localidad
int mostrarClientesAvellaneda (eCliente clientes[], int tama, eLocalidad localidad[], int taml);

//Segundo informe referido a localidad
int mostrarJuegosAlquiladosEnJunin(eCliente clientes[], int tama, eLocalidad localidad[], int taml, eJuego juegos[],
                                   int tam, eAlquiler alquiler[], int tamc);

int mostrarClienteSinAlquilar(eAlquiler alquileres[], int tamA, eCliente clientes[], int tamC, eLocalidad localidades[], int tamL);

int telefonosPorFecha(eAlquiler alquileres[], int tamA, eCliente clientes[], int tamC);

int mostrarJuegosMujeres(eAlquiler alquileres[], int tamA, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCAT);


int mostrarRecaudacionPorFecha(eCliente clientes[], eAlquiler alquiler[], eJuego juegos[],int tama,int tamc, int tam);



int mostrarJuegosSinAlquilar(eAlquiler alquileres[], int tamA,eJuego juegos[], int tam, eCategoria categorias[], int tamC);
//no llegue a documentar todo, profe

int juegoFavoritoHombres(eAlquiler alquileres[], int tamA,eCliente clientes[], int tamCl, eJuego juegos[],
                         int tamJ, eCategoria categorias[], int tamC);

int mostrarClientesJuego(eAlquiler alquileres[], int tamA,eCliente clientes[], int tamC, eJuego juegos[], int tamJ,eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamL);



