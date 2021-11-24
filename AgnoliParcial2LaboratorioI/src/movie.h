/*
 * movie.h
 *
 *  Created on: 24 nov. 2021
 *      Author: Nahue
 */

#ifndef MOVIE_H_
#define MOVIE_H_

struct
{
	int id_peli;
	char titulo[30];
	char genero [30];
	int duracion;
}typedef eMovie;


/**
 * @fn eMovie pelicula_new*()
 * @brief inicia los datos de una pelocula en datos genericos
 *
 * @return retorna la pelicula
 */
eMovie* pelicula_new();

/**
 * @fn eMovie pelicula_newParametros*(char*, char*, char*, char*)
 * @brief carga los datos de la pelicla a la estructura.
 *
 * @param idStr puntero a char, id de pelicula
 * @param tituloStr puntero a char, titulo de la pelicula.
 * @param generoStr puntero a char, genero de la pelocula
 * @param duracionStr puntero a char, duracion de la pelicula
 * @return pelicula con los datos cargados.
 */
eMovie* pelicula_newParametros(char* idStr,char* tituloStr,char* generoStr,char* duracionStr);

/**
 * @fn int pelicula_MostrarPelicula(eMovie*)
 * @brief muetra una pelicula
 *
 * @param unaPeli puntero a estructura eMovie*
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int pelicula_MostrarPelicula(eMovie* unaPeli);

/**
 * @fn void pelicula_delete(eMovie*)
 * @brief borra los elementos de una pelocula
 *
 * @param unaPeli puntero a estructura eMovie*
 */
void pelicula_delete(eMovie* unaPeli);

/**
 * @fn int pelicula_setId(eMovie*, int)
 * @brief carga el id de una peli
 *
 * @param unaPeli punteor a estructura eMovie*
 * @param id int id peli
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int pelicula_setId(eMovie* unaPeli,int id);

/**
 * @fn int pelicula_getId(eMovie*, int*)
 * @brief obtiene el id de una peli
 *
 * @param unaPeli puntero a esturctura eMovie*
 * @param pId punteor a entero
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int pelicula_getId(eMovie* unaPeli,int* pId);

/**
 * @fn int pelicula_setTitulo(eMovie*, char*)
 * @brief carga el titulo de una peli
 *
 * @param unaPeli puntero a esturctura eMovie*
 * @param pTitulo punteor a char
 * @return  todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int pelicula_setTitulo(eMovie* unaPeli,char* pTitulo);

/**
 * @fn int pelicula_getTitulo(eMovie*, char*)
 * @brief obtiene el titutl odeu na pelicula
 *
 * @param unaPeli puntero a esturctura eMovie
 * @param pTitulo puntero a char
 * @return  todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int pelicula_getTitulo(eMovie* unaPeli,char* pTitulo);

/**
 * @fn int pelicula_setGenero(eMovie*, char*)
 * @brief carga el genero de una pelicula
 *
 * @param unaPeli punteor a estructura eMovie
 * @param pGenero punteor a char
 * @return  todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int pelicula_setGenero(eMovie* unaPeli,char* pGenero);

/**
 * @fn int pelicula_getGenero(eMovie*, char*)
 * @brief obtiene el genero de uan peli
 *
 * @param unaPeli punteor a esturctura eMovie
 * @param pGenero punteor a char
 * @return  todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int pelicula_getGenero(eMovie* unaPeli,char* pGenero);

/**
 * @fn int pelicula_setDuracion(eMovie*, int)
 * @brief carga la duracion de una pelicula
 *
 * @param unaPeli punteor a estructura eMovie*
 * @param duracion duracion de la peli
 * @return  todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int pelicula_setDuracion(eMovie* unaPeli,int duracion);


/**
 * @fn int pelicula_getDuracion(eMovie*, int*)
 * @brief busca la pelicula segun su duracion
 *
 * @param unaPeli puntero a estructura eMovie*
 * @param pDuracion puntero a entero, contiene la duracion de la peli
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int pelicula_getDuracion(eMovie* unaPeli,int* pDuracion);


/**
 * @fn int pais_comparar1Dosis(void*, void*)
 * @brief compara 2 peliculas , su genero y duracion.
 *
 * @param pais1 puntero a void, recibe una peli.
 * @param pais2 puntero a void, recibe una peli.
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */

int pelicula_ordenarGeneroDuracion(void* peli1, void* peli2);


/**
 * @fn void pelicula_asignarNumAleatorio*(void*)
 * @brief carga datos al azar en el campo duracion.
 *
 * @param unaPelicula puntero a estructura eMovie*, contiene los datos de las peliculas.
 */
void* pelicula_asignarNumAleatorio(void* unaPelicula);


/**
 * @fn int peliculas_filtrarPeliculaDrama(void*)
 * @brief filtra las peliculas genero drama
 *
 * @param pElement puntero a vod, recibe una peli
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int peliculas_filtrarPeliculaDrama(void * pElement);

/**
 * @fn int peliculas_filtrarPeliculaComedy(void*)
 * @brief filtra por comedia
 *
 * @param pElement puntero a void
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int peliculas_filtrarPeliculaComedy(void * pElement);

/**
 * @fn int peliculas_filtrarPeliculaRomance(void*)
 * @brief filtra por romance
 *
 * @param pElement puntero a void
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int peliculas_filtrarPeliculaRomance(void * pElement);

/**´
 * @fn int peliculas_filtrarPeliculaAdventure(void*)
 * @brief filtra por aventura
 *
 * @param pElement puntero a void
 * @return todoOk(0) si hay error. En caso de no haber error todoOk(1).
 */
int peliculas_filtrarPeliculaAdventure (void * pElement);

#endif /* MOVIE_H_ */
