

  /*  environ es una variavle char**, es un array de punteros a strings, terminado en NULL*/


#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[]){

    char **var;

    for(var = environ; *var != NULL; ++var)

        printf("%s\n", *var);

    return 0;
    
}
