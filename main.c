#include <stdio.h>
#include<stdlib.h>
#include<string.h>



void main(int argc, char const *argv[]) {
  FILE *archivo;
 
  archivo = fopen("prueba.txt","r");
  int opcion;
  int filas;
  int columnas;

  do{
   printf("                    Bienvenido \n\n\n");
   printf("1.Empezar el juego\n");
   printf("2.Cargar archivo\n");
   printf("3.Salir\n");
  scanf("%d",&opcion);
  if (opcion==3)
    exit(0);

  if(opcion==2)
   fscanf(archivo,"%d\n%d",&filas,&columnas);
 printf("Filas : %d \n",&filas);
 printf("Columnas : %d \n",&columnas);



   if (opcion==1)
  datosMatriz();

  if ((opcion!=1)&&(opcion!=2)) {
   printf("Error opcion incorrecta intente nuevamente \n");
  }
 }while ((opcion!=1)&&(opcion!=2));


}
