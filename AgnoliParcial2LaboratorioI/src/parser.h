#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos de las peliculas desde el archivo movies.csv (modo texto).
 *
 * \param pFile char* puntero a char(direccion de memoria del archivo).
 * \param pArrayPeliculas LinkedList* puntero a estructura de la lista de peliculas LinkedList.
 * \return int todoOk(0) si hay error. En caso de no haber error todoOk(1).
 *
 */
int parser_PeliculasViaTexto(FILE* pFile , LinkedList* pArrayPeliculas);


#endif /* PARSER_H_ */
