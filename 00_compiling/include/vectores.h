#ifndef __VECTORES_H__//si no está definida la constante, la define.
#define __VECTORES_H__

#include "general.h"

#ifdef __cplusplus //la define sólo al compilar
extern "C"{
#endif

    extern int *sumar(int resultado[DIM],int op_1[DIM], int op_2[DIM]); //Declaración de la función

#ifdef __cplusplus
    }//Si ponemos ésto sólo compila en C++
#endif

#endif
