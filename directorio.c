/* las librerias a utilizar */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>


void copy_file(char *ruta,char *destino){
    
    FILE *fptr1, *fptr2;
    char  c;
 
 
    // Open one file for reading
    fptr1 = fopen(ruta, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", );
        exit(0);
    }
 

 
    // Open another file for writing
    fptr2 = fopen(destino, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", destino);
        exit(0);
    }
 
    // Read contents from file
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
 
    printf("\nContents copied to %s", destino);
 
    fclose(fptr1);
    fclose(fptr2);
  

}

void listar_dir ( char * origen,char * destino)

{
    DIR * d;

    /* se abre un directorio "dir_name".  dado el path */

    d = opendir (origen);

    
    printf("abriendo el directorio %s\n",origen);
    printf("\n");
    
    /* revisa si se puede abrir */
    
    if (! d) {
        fprintf (stderr, " No se puede abrir el directorio '%s': %s\n",
                 origen, strerror (errno));
        exit (EXIT_FAILURE);
    }
    while (1) {
        
        struct dirent * entry;
        char * d_name;

        /* obtiene entradas subsecuentes. */
        entry = readdir (d);
        if (! entry) {
            /*  si no hay entradas  */
            break;
        }
        
        d_name = entry->d_name;
        /* imprime el nombre del archivo y el directorio. */
	    printf ("%s/%s\n", origen, d_name);


        /* revisa si es un directorio */
        if (entry->d_type == DT_DIR) {

            /* revisa si el directorio no es  "d" or d's parent. */
            if((strcmp(d_name,".")!=0)&&(strcmp(d_name,"..")!=0)) {
          
                int path_length;
                char path[PATH_MAX];
 
                path_length = snprintf (path, PATH_MAX,
                                        "%s/%s", origen, d_name);
                printf ("%s\n", path);
                if (path_length >= PATH_MAX) {
                    fprintf (stderr, " tamaño del Path fuera de rango.\n");
                    exit (EXIT_FAILURE);
                }
                /* realiza la llamada recursiva con el nuevo path. */
                listar_dir (path,destino);
		copy_file(path,destino);
                
            }
	    }
    }
    /*  cierra el directorio */
    if (closedir (d)) {
        fprintf (stderr, " No se puede abrir '%s': %s\n",
                 origen, strerror (errno));
        exit (EXIT_FAILURE);
    }
}


int main(int argc, char *argv[])
{
    // Directorio de origen
    char origen[100];
    char destino[100];
    // Input del directorio
    printf("Introduzca el directorio:\n ");
    scanf("%s", origen);
    printf("\n");
    printf("Introduzca la direccion del destino:\n ");
    scanf("%s",destino);
    // llamada de la función
    listar_dir (origen,destino);
    return 0;




}
