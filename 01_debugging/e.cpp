#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "interfaz.h"

int factorial(int n){
    return n==0 ? 1 : n * factorial(n-1);
}

double e(double error){
    double result = 0,
           term;
    for(int i=0; (term = 1. / factorial(i)) > error; i++, result += term);

    return result;
}


int main(int argc, const char *argv[]){

    double error;

    if (argc < 2)
        print_usage(argv[0]);

    error = atof(argv[1]);
    printf("e = %lf\n", e(error));



	return EXIT_SUCCESS;
}
