#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//#include "alquiler.h"



#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct
{
    int idLocalidad;
    char descripcion[51];
}eLocalidad;


typedef struct
{
    int isEmpty;
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    int telefono;
    int idLocalidad;
} eCliente;

#endif // CLIENTE_H_INCLUDED


/** \brief Pide datos y da de alta un cliente
 * \param Estructura array clientes[]
 * \param tamc tamaño de vector clientes
 * \param puntero a Id que se ira incrementando en cada carga
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int altaCliente (eCliente clientes[], int tamc, int* pId, eLocalidad localidad[], int taml);




/** \brief Busca cliente de acuerdo a un id
 * \param Estructura array clientes[]
 * \param tamc tamaño de vector clientes
 * \param id que se comparara con otro en la busqueda
 * \return Retorna indice de la posicion
 */
int buscarCliente (eCliente clientes[], int tamc, int id);


/** \brief Busca posicion libre
 * \param Estructura array clientes[]
 * \param tamc tamaño de vector clientes
 * \return Retorna indice del primer lugar libre
 */
int buscarLibre (eCliente clientes[], int tamc);


/** \brief Cambia el id del cliente, por el nombre del mismo
 * \param Id que se pasara para comparar
 * \param Estructura array clientes[]
 * \param tamc tamaño de vector clientes
 * \param descripcion que se cargara en vez del id
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int cargarDescripcionCliente(int id, eCliente clientes[], int tamc, char descripcion[]);


/** \brief Inicializa los clientes con isEmpty en 1
 * \param Estructura array clientes[]
 * \param tamc tamaño de vector clientes
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int inicializarClientes (eCliente clientes[], int tamc);


/** \brief Menu de opciones ABM
 * \return Retorna opcion ingresada
 */
int menu ();


/** \brief Menu de informes
 * \return Retorna opcion ingresada
 */
int menuInformes ();


/** \brief Menu de modificaciones
 * \return Retorna opcion ingresada
 */
int menuModificaciones ();


/** \brief Modifica la opcion deseada
 * \param Estructura array clientes[]
 * \param tamc tamaño de vector clientes
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int modificarCliente(eCliente clientes[], int tamc, eLocalidad localidad[], int taml);


/** \brief Muestra un cliente
 * \param Estructura de un cliente
 */
void mostrarCliente (eCliente unCliente, eLocalidad localidad[], int taml);


/** \brief Muestra clientes activos
 * \param Estructura array clientes[]
 * \param tamc tamaño de vector clientes
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int mostrarClientes(eCliente clientes[], int tamc, eLocalidad localidad[], int taml);


/** \brief Ordena clientes segun criterios pedidos
 * \param Estructura array clientes[]
 * \param tamc tamaño de vector clientes
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int ordenarClientes (eCliente clientes[], int tamc);


/** \brief Muestra una localidad
 * \param Estructura de una localidad
 */
void mostrarLocalidad (eLocalidad unaLocalidad);


/** \brief Muestra localidades activas
 * \param Estructura array localidades[]
 * \param taml tamaño de vector localidades
 * \return Retorna todoOk para verificar si se pudo realizar correctamente
 */
int mostrarLocalidades(eLocalidad localidad[], int taml);


int cargarDescripcionLocalidad(int id, eLocalidad localidad[], int taml, char descripcion[]);



