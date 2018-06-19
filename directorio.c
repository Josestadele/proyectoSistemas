/* las librerias a utilizar */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>

/* Rutina para que copie */
void copy_file(char * ruta ,char *destino) {
 struct dirent*df;
 DIR * d ;
 d = opendir (destino);

    if (! d) {
        fprintf (stderr, " No se puede abrir el directorio '%s': %s\n",
                 destino, strerror (errno));
        exit (EXIT_FAILURE);
    }

 while((df =readdir(d)) != NULL) {

    FILE*copy=fopen(ruta,"r");
  
    if(copy) {

     printf("\n leyendo %s archivo...",ruta);
     char strDestFile[PATH_MAX];
     sprintf(strDestFile, "%s/%s",destino,ruta);
     printf("\n archivo copiado = %s\n", strDestFile);           
    
     FILE* copy2  = fopen(strDestFile, "w");    /*File Pointer to write in file*/
                if(copy2)
                {
                    char buffer[PATH_MAX];    /*Buffer to store files content*/

                        while(fgets(buffer,PATH_MAX, copy))
                        {
                            fputs(buffer,copy2);
                        }
                    fclose(copy2);
                }

                 else{
                 printf("\n no es posible abrir el archivo %s", strDestFile);
                }
    fclose(copy);
    }

}
 closedir(d);

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
           
            }
	    
        }
        
            if(entry->d_type==DT_REG) {

             copy_file(d_name,destino);
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
