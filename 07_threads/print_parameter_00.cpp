//
//  Print_parameter_00.cpp
//  
//
//  Created by Roberto Betés on 26/10/16.
//  Sumar dos parametros con una función que acepta un puntero a void
//  para luego hacerle un cast al tipo que necesitamos


#include <stdio.h>
#include <stdlib.h>

int suma (void *parametros){
    
    //Hacemos un cast al argumento de entrada q en éste caso es un puntero a enteros
    int *mi_parametro = (int *) parametros;
    
    return *mi_parametro + *(mi_parametro + 1);
}

int main() {
    
    int param[] = {2, 3};
    
    printf( "%i\n", suma(param));
    
    return EXIT_SUCCESS;
}
