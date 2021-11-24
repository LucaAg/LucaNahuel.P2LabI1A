/*
 * Controller.h
 *
 *  Created on: 21 nov. 2021
 *      Author: Nahue
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/**
 * @fn int controller_cargarViaTexto(LinkedList*, int)
 * @brief carga los datos via texto
 *
 * @param pArrayListaPaises
 * @param banderaGenero
 * @return
 */
int controller_cargarViaTexto(LinkedList* pArrayListaPaises, int banderaGenero);



/**
 * @fn int controller_listarPeliculas(LinkedList*)
 * @brief muestra las peliculas
 *
 * @param pArrayPeliculas
 * @return
 */
int controller_listarPeliculas(LinkedList* pArrayPeliculas);

/**
 * @fn int controller_asignarValoresAzar(LinkedList*)
 * @brief asigna valores al azar a la duracion
 *
 * @param pArrayListaPaises
 * @return
 */
int controller_asignarValoresAzar(LinkedList* pArrayListaPaises);


/**
 * @fn int controller_ordenarPeliculas(LinkedList*)
 * @brief ordena las peliculas segun criterio
 *
 * @param pArrayPeliculas
 * @return
 */
int controller_ordenarPeliculas(LinkedList* pArrayPeliculas);

int controller_filtrarPorDrama(LinkedList* pArrayPeliculas);
int controller_filtrarPorRomance(LinkedList* pArrayPeliculas);
int controller_filtrarPorComedy(LinkedList* pArrayPeliculas);
int controller_filtrarPorAdventure(LinkedList* pArrayPeliculas);



/**
 * @fn int controller_guardarComoTexto(char*, LinkedList*)
 * @brief guarda archivo como texto
 *
 * @param path
 * @param pArrayListaPaises
 * @return
 */
int controller_guardarComoTexto(char* path , LinkedList* pArrayListaPaises);


/**
 * @fn int controller_verificarEstadisticasCargadas(LinkedList*)
 * @brief Recorre la lista de peliculas verificando si hay datos cargados o no.
 *
 * @param pArrayPeliculas puntero a la lista LinkedList*.
 * @return 1 si hay peliculas cargadas. Retorna 0 si no hay peliculas cargadas.
 */
int controller_verificarEstadisticasCargadas(LinkedList* pArrayPeliculas);
#endif /* CONTROLLER_H_ */
