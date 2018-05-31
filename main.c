#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/wait.h>


  int matriz[20][20];
  int filas;
  int columnas;




int contarVecinos(int fila,int columna,int matriz[20][20]) {
    int vecinos = 0;

    if(columna!=1){
    if(matriz[fila][columna-1]=1)
    vecinos++;}

    if(columna!=20){
    if(matriz[fila][columna+1]=1)
    vecinos++;}

    if(fila!=20){
    if(matriz[fila-1][columna]=1)
    vecinos++;}

    if(fila!=1){
    if(matriz[fila+1][columna]=1)
    vecinos++;}

    if((columna!=1)&&(fila!=20)){
    if(matriz[fila-1][columna-1]=1)
    vecinos++;}

    if((columna!=20)&&(fila!=1)){
    if(matriz[fila+1][columna+1]=1)
    vecinos++;}

    if((columna!=1)&&(fila!=1)){
    if(matriz[fila+1][columna-1]=1)
    vecinos++;}

    if((columna!=20)&&(fila!=20)){
    if(matriz[fila-1][columna+1]=1)
    vecinos++;}
 return vecinos;
  }





void llenarMatriz(int *filas, int *columnas, int matriz[20][20]){

	FILE *archivo;
	archivo = fopen("prueba.txt","r");

	fscanf(archivo,"%d\n%d",filas,columnas);
	printf("Filas : %d \n",*filas);
 	printf("Columnas : %d \n",*columnas);

	for ( int i = 0 ; i < *filas; i++ ) {
		for ( int j = 0 ; j < *columnas ; j++ ){
                	fscanf(archivo,"%d",&matriz[i][j]);
	  	}
	}
	fclose(archivo);
}


void imprimirMatriz(int *filas, int *columnas, int matriz[20][20]){
	//printf("Filas : %d \n",*filas);
 	//printf("Columnas : %d \n",*columnas);

	for ( int i = 0 ; i < *filas ; i++ ) {
            for ( int j= 0 ; j < *columnas ; j++ ) {
                printf("%d ",matriz[i][j]);
            }
            printf("\n");
        }

}



void generacionesMatriz(int *filas, int *columnas,int matriz[20][20]){
int vecinos=0;
int row= *filas;
int col= *columnas;
int matrizCopia[row][col];




for(int i = 1; i <= row; i++) {
           for(int j = 1; j <= col; j++) {
            matrizCopia[row][col]=matriz[row][col];
           }
      }
    for (int i=1;i<=row;i++){
      for(int j=1;j<=col;j++){
        if(matriz[i][j]==1){
          vecinos=contarVecinos(row,col,matriz);
          if((vecinos==3)||(vecinos==2)){
            matrizCopia[i][j]=0;
          }

        }
        else{
          if ((matriz[i][j]==0)) {
          vecinos=contarVecinos(row,col,matriz);
          if((vecinos==3)||(vecinos==2)){
          matrizCopia[i][j]=1;
          }
          }
        }
      }
    }




    for(int i = 1; i <= row; i++) {
               for(int j = 1; j <= col; j++) {
                matriz[row][col]=matrizCopia[row][col];
               }
          }

       for ( int a = 0 ; a < row ; a++ ) {
                 for ( int b= 0 ; b < col ; b++ ) {
                     printf("%d ",matrizCopia[a][b]);
                 }
                 printf("\n");}



}

void main(int argc, char const *argv[]) {
  int opcion,pid;


  do{
system("clear");
   printf("                    Bienvenido \n\n\n");
   printf("1.Empezar el juego\n");
   printf("2.Creditos\n");
   printf("3.Salir\n");
  scanf("%d",&opcion);
  if (opcion==3)
    exit(0);

  if(opcion==1){
    int num=0;
 system("clear");
   pid = fork();

    if(pid < 0) {
        printf("Error");
        exit(1);
    } else if (pid == 0) {
      llenarMatriz(&filas,&columnas,matriz);
      imprimirMatriz(&filas,&columnas,matriz); 
        exit(0);
    } else  {
        wait(NULL);
    }

printf("\n\nIndique cantidad de generaciones:\n");
scanf("%d",&num);

for(int n=1;n<=num;n++){

printf("\n\n\n");
generacionesMatriz(&filas,&columnas,matriz);


}

}

   if (opcion==2){
		 system("clear");
		pid = fork();

    if(pid < 0) {
        printf("Error");
        exit(1);
    } else if (pid == 0) {
        printf("Integrantes: \n\n\n");
		 printf("Jose Manuel Gonzalez\n\n");
		 printf("Franco Marino\n\n");
		 printf("Carlos Sanoja\n\n");
printf("Se agregaron referecias a enlaces, revisar comentarios en esta seccion del codigo\n");
        exit(0);
    } else  {
        wait(NULL);
    }
  /*   Se utilizaron las siguientes fuentes como apoyo para la realización del proyecto:

    Para manejo de archivos:	https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C/Manejo_de_archivos

    Para el entendimiento del juego y las respectivas funciones encargadas
  de realizar los cambios y generaciones del mundo: https://codereview.stackexchange.com/questions/61591/game-of-life-generation-procession-algorithm

*/
		 exit(0);

	 }


  if ((opcion!=1)&&(opcion!=2)) {
   printf("Error opcion incorrecta intente nuevamente \n");
  }
 }while ((opcion!=1)&&(opcion!=2));


}
