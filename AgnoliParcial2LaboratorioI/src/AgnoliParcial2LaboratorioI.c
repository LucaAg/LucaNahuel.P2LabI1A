/*
 ============================================================================
 Name        : AgnoliParcial2LaboratorioI.c
 Author      : nahue
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include <time.h>

int main(void)
{
	setbuf(stdout,NULL);
	srand(time(NULL));
	LinkedList* listaPeliculas= ll_newLinkedList();
	char opcion='s';
	int banderaGenero=0;
	int archivoCargado=0;

	do
	{
		switch(menu())
		{
			case 1:
				controller_cargarViaTexto(listaPeliculas, banderaGenero);
				archivoCargado=1;
				break;
			case 2:
				controller_listarPeliculas(listaPeliculas);
				break;
			case 3:
				if(controller_verificarEstadisticasCargadas(listaPeliculas))
				{
					printf("Ya hay estadisticas cargadas!\n");
				}
				else
				{
					controller_asignarValoresAzar(listaPeliculas);
				}
				break;
			case 4:
				switch(menuGenero())
				{
				case 1:
					controller_filtrarPorDrama(listaPeliculas);
					break;
				case 2:
					controller_filtrarPorComedy(listaPeliculas);
					break;
					case 3:
						controller_filtrarPorRomance(listaPeliculas);
						break;
					case 4:
						controller_filtrarPorAdventure(listaPeliculas);
					break;
				default:
					printf("Error, opcion no valida(1-4)! \n");
						break;
				}
				banderaGenero=1;
				break;
			case 5:
				controller_ordenarPeliculas(listaPeliculas);
				break;
			case 6:
				if(archivoCargado==1)
				{
					controller_guardarComoTexto("movies.csv", listaPeliculas);
				}
				else
				{
					printf("Error, no se ha cargado la lista principal(movies.csv)\n");
				}
				break;
			case 7:
				pedirCaracter(&opcion, "Desea continuar en el menu? (s=Si/n=No): \n",
						"Error, opcion invalida. Vuelva a intentarlo (s=Si/n=No): \n",'s', 'n');
				if(opcion == 'n')
				{
					ll_deleteLinkedList(listaPeliculas);
				}
				break;
			default:
				printf("Error, opcion no valida(1-9)\n");
				break;
		}
	}while(opcion=='s');


	return EXIT_SUCCESS;
}
