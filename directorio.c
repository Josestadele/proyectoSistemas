/* las librerias a utilizar */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>


void listar_dir (const char * origen)

{
    DIR * d;

    /* se abre un directorio "dir_name".  dado el path */

    d = opendir (origen);

    
    printf("abriendo el directorio %s\n",origen);
    
    /* revisa si se puede abrir */
    
    if (! d) {
        fprintf (stderr, " No se puede abrir el directorio '%s': %s\n",
                 origen, strerror (errno));
        exit (EXIT_FAILURE);
    }
    while (1) {
        struct dirent * entry;
        const char * d_name;

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
                listar_dir (path);
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


int main(int argc, char const *argv[])
{
    
    listar_dir ("/Users/krlos/Documents/7mo Semestre"); /* ponen el path a abrir */
    return 0;
}
