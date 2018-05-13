#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

// defini los paramateros de la matiz
struct  parametros  {
char matriz [7][7];
};

void llenarMatriz(char m[7][7])  {
        
        for ( int i = 0 ; i < 7 ; i++ ) {
            for ( int j = 0 ; j < 7 ; j++ ) {
                m[i][j] = '*';
            }
        }
    }

void  imprimirMatriz(char m[7][7]){
     for ( int i = 0 ; i < 7 ; i++ ) {
            for ( int j= 0 ; j < 7 ; j++ ) {
                printf("%c ",m[i][j]);
            }
            printf("\n");
        }


}    




int main() {
    
    struct  parametros  p1;//Estoy inicializando la variable para ingresar a las structura
    
    /*p1.matriz; // La variable del parametro entra y pide la matriz*/

    llenarMatriz(p1.matriz); // pasa por parametro la matriz para crearla 
    imprimirMatriz(p1.matriz);// pasa por parametos la matriz para imprimir 

    
}