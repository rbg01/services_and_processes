#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "terminal.h"
#include "general.h"
#include "vectores.h"

int main(int argc, const char *argv[]){

    int vector_1[DIM];
    int vector_2[DIM];
    int resultado[DIM];

    preguntar (vector_1);
    preguntar (vector_2);
    imprimir (sumar(resultado, vector_1, vector_2));




	return EXIT_SUCCESS;
}
