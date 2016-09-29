#include "vectores.h"

int *sumar(int resultado[DIM], int op_1[DIM], int op_2[DIM]){

    for (int i=0; i<DIM; i++)
        resultado[i] = op_1[i] + op_2[i];

    return (int *)resultado;

}
