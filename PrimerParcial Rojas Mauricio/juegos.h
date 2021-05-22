#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct{
int id;
char descripcion[51];
}eCategoria;


typedef struct{
int codigo;
char descripcion[20];
float importe;
int idCategoria;
}eJuego;




#endif // JUEGOS_H_INCLUDED


/** \brief Cambia el id del juego, por el nombre del mismo
 * \param Id que se pasara para comparar
 * \param Estructura array juegos[]
 * \param tam tamaño de vector juegos
 * \param descripcion que se cargara en vez del id
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int cargarDescripcionJuego(int id, eJuego juegos[], int tam, char descripcion[]);


/** \brief Cambia el id del juego, por el importe del mismo
 * \param Id que se pasara para comparar
 * \param Estructura array juegos[]
 * \param tam tamaño de vector juegos
 * \param importe que se cargara en vez del id
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int cargarPrecioJuego(int idJuego, eJuego juegos[], int tam, float* precioJuego);


/** \brief Muestra un juego
 * \param Estructura de un juego
 */
void mostrarJuego(eJuego unJuego);


/** \brief Muestra todos los juegos
 * \param Estructura array juegos[]
 * \param tam tamaño de vector juegos
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int mostrarJuegos (eJuego juegos[], int tam);
