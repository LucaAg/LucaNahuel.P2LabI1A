/*
 * pais.c
 *
 *  Created on: 21 nov. 2021
 *      Author: Nahue
 */
#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

eMovie* pelicula_new()
{
	eMovie* nuevaPelicula;

	nuevaPelicula = (eMovie*) malloc(sizeof(eMovie));
	if(nuevaPelicula != NULL)
	{
		nuevaPelicula->id_peli= 0;
		strcpy(nuevaPelicula->titulo,"--");
		strcpy(nuevaPelicula->genero,"--");
		nuevaPelicula->duracion=0;
	}

	return nuevaPelicula;
}

eMovie* pelicula_newParametros(char* idStr,char* tituloStr,char* generoStr,char* duracionStr)
{
	eMovie* nuevaPelicula;

	nuevaPelicula = pelicula_new();
	if(nuevaPelicula != NULL)
	{
		if( !(pelicula_setId(nuevaPelicula,atoi(idStr))
				&& pelicula_setTitulo(nuevaPelicula,tituloStr)
				&& pelicula_setGenero(nuevaPelicula,generoStr)
				&&	pelicula_setDuracion(nuevaPelicula,atoi(duracionStr)) ) )
		{
			free(nuevaPelicula);
			nuevaPelicula=NULL;
		}
	}
	return nuevaPelicula;
}



int pelicula_MostrarPelicula(eMovie* unaPeli)
{
	int todoOk=0;
	int idPeli;
	char titulo[30];
	char genero[30];
	int duracion;

	if(unaPeli != NULL)
	{
		pelicula_getId(unaPeli, &idPeli);
		pelicula_getTitulo(unaPeli, titulo);
		pelicula_getGenero(unaPeli, genero);
		pelicula_getDuracion(unaPeli, &duracion);
		printf("%-4d%-30s%-30s%-10d\n",idPeli,titulo,genero,duracion);
		todoOk=1;
	}
	return todoOk;
}


void pelicula_delete(eMovie* unaPeli)
{
	if(unaPeli!=NULL)
	{
		free(unaPeli);
	}
}

int pelicula_setId(eMovie* unaPeli,int id)
{
	int todoOk=0;
	if(unaPeli!=NULL && id>=0)
	{
		unaPeli->id_peli=id;
		todoOk=1;
	}
	else
	{
		printf("Error al cargar el id de la pelicula.\n");
	}
	return todoOk;
}

int pelicula_getId(eMovie* unaPeli,int* pId)
{
	int todoOk=0;
	if(unaPeli!=NULL && pId!=NULL)
	{
		*pId=unaPeli->id_peli;
		todoOk=1;
	}
	return todoOk;
}

int pelicula_setTitulo(eMovie* unaPeli,char* pTitulo)
{
	int todoOk=0;
	if(unaPeli!=NULL && pTitulo!=NULL)
	{
		if(strlen(pTitulo) < 30 && strlen(pTitulo)>1)
		{
			strcpy(unaPeli->titulo,pTitulo);
			todoOk=1;
		}
		else
		{
			printf("Error al cargar el titulo de la pelicula.\n");
		}
	}
	return todoOk;
}

int pelicula_getTitulo(eMovie* unaPeli,char* pTitulo)
{
	int todoOk=0;
	if(unaPeli!=NULL && pTitulo!=NULL)
	{
		strcpy(pTitulo,unaPeli->titulo);
		todoOk=1;
	}
	return todoOk;
}

int pelicula_setGenero(eMovie* unaPeli,char* pGenero)
{
	int todoOk=0;
	if(unaPeli!=NULL && pGenero!=NULL)
	{
		if(strlen(pGenero) < 30 && strlen(pGenero)>1)
		{
			strcpy(unaPeli->genero,pGenero);
			todoOk=1;
		}
		else
		{
			printf("Error al cargar el genero de la pelicula.\n");
		}
	}
	return todoOk;
}

int pelicula_getGenero(eMovie* unaPeli,char* pGenero)
{
	int todoOk=0;
	if(unaPeli!=NULL && pGenero!=NULL)
	{
		strcpy(pGenero,unaPeli->genero);
		todoOk=1;
	}
	return todoOk;
}

int pelicula_setDuracion(eMovie* unaPeli,int duracion)
{
	int todoOk=0;
	if(unaPeli!=NULL && duracion<=240)
	{
		unaPeli->duracion=duracion;
		todoOk=1;
	}
	return todoOk;
}


int pelicula_getDuracion(eMovie* unaPeli,int* pDuracion)
{
	int todoOk=0;
	if(unaPeli!=NULL && unaPeli!=NULL)
	{
		*pDuracion=unaPeli->duracion;
		todoOk=1;
	}
	return todoOk;
}



int pelicula_ordenarGeneroDuracion(void* peli1, void* peli2)
{
	int todoOk=0;
	char genero[30];
	char genero2[30];
	int duracion;
	int duracion2;
	eMovie* auxPeli1;
	eMovie* auxPeli2;

	auxPeli1 = (eMovie*) peli1;
	auxPeli2 = (eMovie*) peli2;
	if(auxPeli1!=NULL && auxPeli2!=NULL)
	{
		pelicula_getGenero(auxPeli1, genero);
		pelicula_getGenero(auxPeli2, genero2);
		pelicula_getDuracion(auxPeli1, &duracion);
		pelicula_getDuracion(auxPeli2,&duracion2);
		if(strcmp(genero, genero2)> 0)
		{
			todoOk=1;
		}
		else if(strcmp(genero, genero2)< 0)
		{
			todoOk=-1;
		}
		else
		{
			if( strcmp(genero, genero2) == 0 )
			{
				if(duracion > duracion2)
				{
					todoOk=1;
				}
				else if(duracion < duracion2)
				{
					todoOk=-1;
				}
			}
		}
	}
	return todoOk;
}


void* pelicula_asignarNumAleatorio(void* unaPelicula)
{
	int duracionPeli;
	eMovie* auxPelicula;
	int max1=240;
	int min1=100;


	auxPelicula = (eMovie*)unaPelicula;
	if(auxPelicula != NULL)
	{
		duracionPeli = rand() % (max1 - min1 +1 ) + min1;

		pelicula_setDuracion(auxPelicula, duracionPeli);

	}
	return (eMovie*)auxPelicula;
}

int peliculas_filtrarPeliculaDrama(void * pElement)
{
	eMovie* auxPelicula = NULL;
	int todoOk=0;
	auxPelicula = (eMovie*)pElement;
	char genero[30]="Drama";
	if(auxPelicula != NULL)
	{
		if ( strcmp(auxPelicula->genero, genero) == 0)
		{
			todoOk=1;
		}
	}
	return todoOk;
}

int peliculas_filtrarPeliculaAdventure (void * pElement)
{
	eMovie* auxPelicula = NULL;
	int todoOk=0;
	auxPelicula = (eMovie*)pElement;
	char genero[30] = "Adventure";
	if(auxPelicula != NULL)
	{

		if(strcmp(auxPelicula->genero, genero) == 0)
		{
				todoOk=1;
		}
	}
	return todoOk;
}

int peliculas_filtrarPeliculaComedy(void * pElement)
{
	eMovie* auxPelicula = NULL;
	int todoOk=0;
	auxPelicula = (eMovie*)pElement;
	char genero[30]="Comedy";
	if(auxPelicula != NULL)
	{
		if ( strcmp(auxPelicula->genero, genero) == 0)
		{
			todoOk=1;
		}
	}
	return todoOk;
}

int peliculas_filtrarPeliculaRomance(void * pElement)
{
	eMovie* auxPelicula = NULL;
	int todoOk=0;
	auxPelicula = (eMovie*)pElement;
	char genero[30]="Romance";
	if(auxPelicula != NULL)
	{
		if ( strcmp(auxPelicula->genero, genero) == 0)
		{
			todoOk=1;
		}
	}
	return todoOk;
}
