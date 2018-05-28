#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void llenarMatriz(int filas, int columnas, int matriz[20][20]){
	for ( int i = 0 ; i < filas; i++ ) {
            for ( int j = 0 ; j < columnas ; j++ ) 
                fscanf(archivo,"%d",&matriz[i][j]);
				}

}


void imprimirMatriz(int filas, int columnas, int matriz[20][20]){
	for ( int i = 0 ; i < filas ; i++ ) {
            for ( int j= 0 ; j < columnas ; j++ ) {
                printf("%d ",matriz[i][j]);
            }
            printf("\n");
        }	

}



void main(int argc, char const *argv[]) {
  
  int opcion;
  int filas;
  int columnas;
  int matriz[20][20];

  do{
   printf("                    Bienvenido \n\n\n");
   printf("1.Empezar el juego\n");
   printf("2.Cargar archivo\n");
   printf("3.Salir\n");
  scanf("%d",&opcion);
  if (opcion==3)
    exit(0);

  if(opcion==2){
FILE *archivo;
 
  archivo = fopen("prueba.txt","r");
   fscanf(archivo,"%d\n%d",&filas,&columnas);
 printf("Filas : %d \n",filas);
 printf("Columnas : %d \n",columnas);
llenarMatriz(filas,columnas,matriz[20][20]);
imprimirMatriz(filas,columnas,matriz[20][20]);



}

   if (opcion==1)
  exit(0);

  if ((opcion!=1)&&(opcion!=2)) {
   printf("Error opcion incorrecta intente nuevamente \n");
  }
 }while ((opcion!=1)&&(opcion!=2));


}
