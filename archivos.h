#include <stdlib.h>
#include<stdio.h>
#include<string.h>

void leerArchivo(){

  FILE *archivo;
	char linea[100];

	archivo = fopen("prueba.txt","r");

	if (archivo == NULL)
        {
            printf("\nError de apertura del archivo. \n\n");
        }
        else
        {
            printf("\nEl contenido del archivo de prueba es \n\n");
            while(fgets(linea, 100, (FILE*) archivo)) {
          printf("LINEA: %s FIN_DE_LINEA\n", linea);
      }
        }
        fclose(archivo);

}
