#include<stdlib.h>

void datosMatriz(){
int filas;
int columnas;
printf("    A continuacion se pediran los datos para generar la matriz\n");
printf("    Por motivos de simplicidad por favor generar una matriz cuadrada\n\n");
do{
filas=0;
columnas=0;
printf("Introduzca cantidad de filas\n");
scanf("%d",&filas);
printf("\n" );


printf("Introduzca cantidad de columnas\n");
scanf("%d",&columnas);
printf("\n" );
if((filas==0)||(columnas==0)||(filas!=columnas))

  printf("Error numero de filas distinto a numero de columnas y/o tiene valor 0\n\n");

}while((filas!=columnas)||(filas==0)||(columnas==0));
printf("Exito\n");
exit(0);

}
