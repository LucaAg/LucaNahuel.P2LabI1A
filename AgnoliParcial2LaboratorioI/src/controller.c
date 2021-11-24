#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "movie.h"
#include "parser.h"
#include "input.h"
#include "Controller.h"


int controller_cargarViaTexto(LinkedList* pArrayPeliculas, int banderaGenero)
{
	int todoOk=0;
	char archivo[30];
	FILE* f;

	if(pArrayPeliculas!=NULL)
	{
		ll_clear(pArrayPeliculas);
		if(banderaGenero == 0 )
		{
			printf("Ingrese el nombre del archivo a cargar. \nRecomendaciones:\n-movies.csv\n");
		}

		gets(archivo);

		f= fopen(archivo,"r");
		if(f==NULL)
		{
			printf("Error al cargar el archivo en modo texto!\nGracias por usar nuestro sistema.");
		}
		else
		{
			parser_PeliculasViaTexto(f,pArrayPeliculas);
			printf("El archivo en modo texto se ha cargado exitosamente!\n Gracias por usar nuestro sistema.\n");
			todoOk=1;
		}
		fclose(f);
	}
    return todoOk;
}



int controller_listarPeliculas(LinkedList* pArrayPeliculas)
{
	int todoOk=0;
	int tam;
	eMovie* auxPelicula=NULL;
	if(pArrayPeliculas!=NULL)
	{
		tam=ll_len(pArrayPeliculas);
		if(tam>=1)
		{
			todoOk=1;
			printf("-----------------------------------------------------------------------------\n");
			printf("ID |             NOMBRE           |             GENERO           | DURACION |\n");
			printf("-----------------------------------------------------------------------------\n");

			for(int i=0; i<tam; i++)
			{
				auxPelicula = (eMovie*) ll_get(pArrayPeliculas,i);
				pelicula_MostrarPelicula(auxPelicula);
				if(auxPelicula != NULL)
				{
					pelicula_MostrarPelicula(auxPelicula);
				}
			}
		}
	}
	else
	{
		pelicula_delete(auxPelicula);
	}
	return todoOk;
}

int controller_asignarValoresAzar(LinkedList* pArrayPeliculas)
{
	int todoOk=0;
	char opcion;
	if(pArrayPeliculas!=NULL)
	{
		if ( ll_map(pArrayPeliculas, pelicula_asignarNumAleatorio) != NULL )
		{
			pedirCaracter(&opcion, "Desea ver la lista actualizada ? (s=Si / n= No )\n",
					"Error, opcion no valida. Vuelva a intentarlo (s=Si / n= No ): \n", 's', 'n');
			if(opcion == 's')
			{
				controller_listarPeliculas(pArrayPeliculas);
			}
		}
		todoOk=1;
	}
	return todoOk;
}


int controller_ordenarPeliculas(LinkedList* pArrayPeliculas)
{
	int todoOk=0;
	int criterio;

	LinkedList* auxList;

	if(pArrayPeliculas!=NULL)
	{
		auxList= ll_clone(pArrayPeliculas);
		if(auxList!=NULL)
		{
			if(ll_isEmpty(auxList)==0 && ll_containsAll(auxList, pArrayPeliculas) )
			{
				pedirEntero(&criterio, "Ingrese el criterio en el que quiera ordenar: [ascendente 1 (1-9) / 0 descendente (9-1)] \n",
												"Error, opcion invalida. Vuelva a intentarlo: [ascendente 1 (1-9) / 0 descendente (9-1)] \n", 0, 1);
				printf("------------------------------------------------\n");
				printf("           *** ORDENAR PAISES ***                \n");
				printf("------------------------------------------------\n\n");
				ll_sort(auxList, pelicula_ordenarGeneroDuracion, criterio);
				controller_listarPeliculas(auxList);

				ll_deleteLinkedList(auxList);
				todoOk=1;
			}
			else
			{
				printf("Error, no hay pais/es cargado/s en la lista!\nGracias por usar nuestro sistema.\n");
			}

		}
	}
	return todoOk;
}



int controller_filtrarPorDrama(LinkedList* pArrayPeliculas)
{
	int todoOk=0;
	LinkedList* nuevaLista =NULL;
	if(pArrayPeliculas!=NULL)
	{
		nuevaLista =ll_filter(pArrayPeliculas, peliculas_filtrarPeliculaDrama);
		controller_listarPeliculas(nuevaLista);
		controller_guardarComoTexto("peliculasDrama.csv", nuevaLista);
		todoOk=1;

	}
	return todoOk;
}

int controller_filtrarPorRomance(LinkedList* pArrayPeliculas)
{
	int todoOk=0;
	LinkedList* nuevaLista =NULL;
	if(pArrayPeliculas!=NULL)
	{
		nuevaLista =ll_filter(pArrayPeliculas, peliculas_filtrarPeliculaRomance);
		controller_listarPeliculas(nuevaLista);
		controller_guardarComoTexto("peliculasRomance.csv", nuevaLista);
		todoOk=1;

	}
	return todoOk;
}

int controller_filtrarPorComedy(LinkedList* pArrayPeliculas)
{
	int todoOk=0;
	LinkedList* nuevaLista =NULL;
	if(pArrayPeliculas!=NULL)
	{
		nuevaLista =ll_filter(pArrayPeliculas, peliculas_filtrarPeliculaComedy);
		controller_listarPeliculas(nuevaLista);
		controller_guardarComoTexto("peliculasCoemdy.csv", nuevaLista);
		todoOk=1;

	}
	return todoOk;
}

int controller_filtrarPorAdventure(LinkedList* pArrayPeliculas)
{
	int todoOk=0;
	LinkedList* nuevaLista =NULL;
	if(pArrayPeliculas!=NULL)
	{
		nuevaLista =ll_filter(pArrayPeliculas, peliculas_filtrarPeliculaAdventure);
		controller_listarPeliculas(nuevaLista);
		controller_guardarComoTexto("peliculasAdventure.csv", nuevaLista);
		todoOk=1;

	}
	return todoOk;
}

int controller_guardarComoTexto(char* path , LinkedList* pArrayPeliculas)
{
	int todoOk=0;
	FILE* f;
	eMovie* auxPelicula;
	int tam;
	int duracion;
	int idPeli;
	char titulo[30];
	char genero[30];

	if(path!=NULL && pArrayPeliculas!=NULL)
	{
		//archivo tipo texto
		f=fopen(path,"w");

		auxPelicula=pelicula_new();

		tam= ll_len(pArrayPeliculas);

		fprintf(f,"id_peli,titulo,genero,duracion\n");
		for(int i=0; i<tam;i++)
		{
			auxPelicula= (eMovie*) ll_get (pArrayPeliculas,i);
			if(auxPelicula!=NULL)
			{
				pelicula_getId(auxPelicula, &idPeli);
				pelicula_getTitulo(auxPelicula, titulo);
				pelicula_getGenero(auxPelicula, genero);
				pelicula_getDuracion(auxPelicula, &duracion);

				fprintf(f,"%d,%s,%s,%d\n",idPeli,titulo,genero,duracion);
				todoOk=1;
			}
			else
			{
				printf("\nError al guardar el archivo en modo texto!\n\n");
				todoOk=0;
				break;
			}
		}
		printf("\nSe ha guardado el archivo exitosamente!\n\n");
		fclose(f);
	}
	return todoOk;
}




int controller_verificarEstadisticasCargadas(LinkedList* pArrayPeliculas)
{
	eMovie* auxPelicula;
	int tam = ll_len(pArrayPeliculas);

	for(int i=0 ; i < tam; i++)
	{
		auxPelicula= (eMovie*) ll_get(pArrayPeliculas,i);

		if(auxPelicula ->duracion != 0 )
		{
			return 1;
		}

	}
	return 0;
}

