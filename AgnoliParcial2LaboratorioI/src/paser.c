/*
 * parser.c
 *
 *  Created on: 21 nov. 2021
 *      Author: Nahue
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedList.h"
#include "movie.h"
#include "parser.h"
#include "Controller.h"


int parser_PeliculasViaTexto(FILE* pFile , LinkedList* pArrayListaPeliculas)
{
	int todoOk = 0;
	eMovie* peliculaNueva;
	char buffer[4][30];
	int aux;

	if(pFile != NULL && pArrayListaPeliculas != NULL)
	{
		fscanf(pFile,"%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			aux = fscanf(pFile,"%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);
			if(aux == 4)
			{
				peliculaNueva = pelicula_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

				if(peliculaNueva != NULL)
				{
					aux = ll_add(pArrayListaPeliculas, peliculaNueva);
					if(aux != 0)
					{
						pelicula_delete(peliculaNueva);
						break;
					}
					else
					{
						todoOk = 1;
					}
				}
			}
			else
			{
				break;
			}
		}
	}
    return todoOk;
}

