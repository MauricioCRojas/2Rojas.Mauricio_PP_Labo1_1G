#include "cliente.h"
#include "juegos.h"


#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

typedef struct {
int dia;
int mes;
int anio;
}eFecha;


typedef struct {
int isEmpty;
int codAlq;
int codCliente;
int codJuego;
eFecha fechaAlquiler;
}eAlquiler;

#endif // ALQUILER_H_INCLUDED



/** \brief Pide datos y da de alta un alquiler
 * \param Estructura array alquiler[]
 * \param tama tamaño de vector alquiler
 * \param puntero a Id que se ira incrementando en cada carga
 * \param Estructura array clientes[]
 * \param tamc tamaño de vector clientes
 * \param Estructura array juegos[]
 * \param tam tamaño de vector juegos
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int altaAlquiler (eAlquiler alquiler[], int tama, int* pId, eCliente clientes[], int tamc, eJuego juegos[],
                   int tam, eLocalidad localidad[], int taml, eCategoria categoria[], int tamCAT);

/** \brief Busca posicion libre
 * \param Estructura array alquiler[]
 * \param tama tamaño de vector alquiler
 * \return Retorna indice del primer lugar libre
 */
int buscarLibreAlquiler (eAlquiler alquiler[], int tama);


/** \brief Inicializa los alquileres con isEmpty en 1
 * \param Estructura array alquiler[]
 * \param tama tamaño de vector alquiler
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int inicializarAlquiler (eAlquiler alquiler[], int tama);


/** \brief Muestra un alquiler
 * \param Estructura de un alquiler
 * \param Estructura array clientes[]
 * \param tamc tamaño de vector clientes
 * \param Estructura array juegos[]
 * \param tam tamaño de vector juegos
 */
void mostrarAlquiler(eAlquiler unAlquiler, eCliente clientes[], int tamc, eJuego juegos[], int tam);


/** \brief Muestra alquileres activos
 * \param Estructura array alquiler[]
 * \param tama tamaño de vector alquiler
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int mostrarAlquileres (eAlquiler alquiler[], int tama, eCliente clientes[], int tamc, eJuego juegos[], int tam);

