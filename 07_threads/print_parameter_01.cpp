//
//  print_parameter_01.cpp
//  
//
//  Created by Roberto Betés on 26/10/16.
//Sumar dos parametros con una función que acepta un puntero a void
// para luego hacerle un cast al tipo que necesitamos
//
#include <stdlib.h>
#include <stdio.h>

struct TParam {

    int op1;
    int op2;
    
};

int suma (void *parametros){

    struct TParam *p = (struct TParam*) parametros;
    
    int result = 0;
    
    result = p->op1 + p->op2;
    
    return result;
    
}


int main (){


    struct TParam param = {2, 3};
    
    printf("%i", suma(&param));
    
    return EXIT_SUCCESS;
}
