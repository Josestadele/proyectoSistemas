#include <stdio.h>
#include<stdlib.h>
#include<string.h>

  int matriz[20][20];



int contarVecinos(int *filas, int *columnas, int matriz[20][20])  // cuenta el numero de celulas que tiene cada vecino
{
  int count,i,j,x,y;
  for(i = 0; i < *filas; i++){
            for(j = 0; j < *columnas; j++){
                count = 0;
                for(y = -1; y < 2; y++){
                    for(x = -1; x < 2; x++){
                        if(x != 0 && y != 0 && matriz[(i + y) % (*filas)][(j + x) % (*columnas)] == 1){
                        count++;
                        }
                    }
                } 
            }
        }
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



void main(int argc, char const *argv[]) {
  int opcion;
  int filas;
  int columnas;


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
 system("clear");
llenarMatriz(&filas,&columnas,matriz);

imprimirMatriz(&filas,&columnas,matriz);



}

   if (opcion==2){
		 system("clear");
		 printf("Integrantes: \n\n\n");
		 printf("Jose Manuel Gonzalez\n\n");
		 printf("Franco Marino\n\n");
		 printf("Carlos Sanoja\n\n");
		 /* Se utilizaron las siguientes fuentes como apoyo para la realización del proyecto:
		 				https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C/Manejo_de_archivos

						
						*/
		 exit(0);

	 }


  if ((opcion!=1)&&(opcion!=2)) {
   printf("Error opcion incorrecta intente nuevamente \n");
  }
 }while ((opcion!=1)&&(opcion!=2));


}
