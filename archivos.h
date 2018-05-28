#include <stdlib.h>
#include<stdio.h>
#include<string.h>

void leerArchivo(){

  FILE *archivo;
	char linea[100];
  archivo = fopen("prueba.txt","r");
  int sfilas;
  int scolumnas;

	if (archivo == NULL)
        {
            printf("\nError de apertura del archivo. \n\n");
        }
        else
        {
          fscanf(archivo,"%d\n%d",&sfilas,&scolumnas);
          printf("%d\n%d \n",sfilas,scolumnas ); //para comprobar los valores que se imprimen
        }
        fclose(archivo);



}
