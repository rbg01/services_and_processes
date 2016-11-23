#ifndef __TERMINAL_H__//si no está definida la constante, la define.
#define __TERMINAL_H__

#include "general.h"

#ifdef __cplusplus //la define sólo al compilar
extern "C"{
#endif

    extern void preguntar(int vector[DIM]); //Declaración de la función
    extern void imprimir(int vector[DIM]);

#ifdef __cplusplus
    }//Si ponemos ésto sólo compila en C++
#endif

#endif
