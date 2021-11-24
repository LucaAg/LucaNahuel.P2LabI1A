#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

int rangoString(char frase[],int tam)
{
	int todoOk=0;
	if(frase!= NULL && tam>0)
	{
		while(strlen(frase) > tam)
		{
			printf("Error, lo que usted ingreso supera el maximo de caracteres (%d)."
					"\nPor favor, reingreselo: \n",tam);
			fflush(stdin);
			gets(frase);
		}
		todoOk=1;
	}
	return todoOk;
}

int validarStringOrdenado(char frase[])
{
	int todoOk=0;
	int i=0;
	if(frase!=NULL)
	{
		strlwr(frase);
		frase[0]=toupper(frase[0]);
		while(frase[i]!='\0')
		{
			if(frase[i]==' ')
			{
				frase[i+1]=toupper(frase[i+1]);
			}
			i++;
		}

		todoOk=1;
	}
	return todoOk;
}

int validarString(char frase[],int tam)
{
	int flag;
	int esString;
	int i=0;
	if(frase!=NULL)
	{
		flag=0;

		while(i<strlen(frase))
		{
			esString=isalpha(frase[i]);
			if(esString==0 && frase[i]!=' ')
			{
				flag=1;
				while(flag==1)
				{
					printf("Error, no puede ingresar numeros, ni simbolos. \nPor favor vuelva a ingresarlo: \n");
					fflush(stdin);
					gets(frase);
					flag=0;
					i=0;
				}
			}
			else
			{
				fflush(stdin);
				i++;
			}
			rangoString(frase,tam);
		}
		if(!validarStringOrdenado(frase))
		{
			flag=1;
		}
	}
	return flag;
}




int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	char auxEntero[150];

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		gets(auxEntero);
		fflush(stdin);

		while( validarNumeros(auxEntero)==0 ||  atoi(auxEntero) < min || atoi(auxEntero) > max)
		{
			printf("%s", mensajeError);
			gets(auxEntero);
			fflush(stdin);
		}
		*entero = atoi(auxEntero);
		retorno = 0;
	}

	return retorno;
}


int pedirCaracter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2)
{
	int todoOk=-1;
	char caracterIngresado;

	if(caracter!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&caracterIngresado);
		caracterIngresado=tolower(caracterIngresado);

		while(caracterIngresado!= caracterVal1 && caracterIngresado!=caracterVal2)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%c",&caracterIngresado);
			caracterIngresado=tolower(caracterIngresado);
		}
		*caracter=caracterIngresado;
		todoOk=0;
	}
	return todoOk;
}


int validarNumeros(char numeros[])
{
	int todoOk=1;
	if(strlen(numeros) > 0)
		{
			for(int i = 0;i< strlen(numeros);i++)
			{
				if(isdigit(numeros[i]) == 0)
				{
					if(i == 0 && numeros[0] == '-')
					{
	                    todoOk = 1;
					}
					else
					{
						todoOk =0;
					}
				}
			}
		}
	    else
	    {
	        todoOk=0;
	    }
	return todoOk;
}



int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max)
{
	int todoOk = 0;
	char buffer[256];

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		max = strlen(buffer);
		while(!validarString(buffer, max))

		strcpy(cadena, buffer);
		todoOk = 1;
	}

	return todoOk;
}

int menu()
{
	int opcion;

	printf("\n");
	printf("--------------------------------------------------------------------\n");
	printf("                     ***  LISTA DE PELICULAS ***                      \n");
	printf("--------------------------------------------------------------------\n");
	printf("     1. Cargar los datos de las peliculas.\n");
	printf("     2. Imprimir lista.\n");
	printf("     3. Asignar tiempos.\n");
	printf("     4. Filtrar por generos.\n");
	printf("     5. Ordenar por género y duración.\n");
	printf("     6. Guardar películas.\n");
	printf("     7. Salir.\n");

	printf("Ingrese opcion: \n");
	scanf("%d",&opcion);
	fflush(stdin);
	return opcion;
}

int menuGenero()
{
	int opcion;

	printf("\n");
	printf("--------------------------------------------------------------------\n");
	printf("                           *** GENEROS ***                      \n");
	printf("--------------------------------------------------------------------\n");
	printf("     1. Drama.\n");
	printf("     2. Comedy.\n");
	printf("     3. Romance.\n");
	printf("     4. Adventure.\n");

	printf("Ingrese opcion: \n");
	scanf("%d",&opcion);
	fflush(stdin);
	return opcion;
}
