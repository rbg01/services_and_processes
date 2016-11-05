//
//  primo.cpp
//  
//
//  Created by Roberto Betés on 3/11/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


#define N 200

bool es_primo(int candidato){
    
    for (int divisor=2; divisor<candidato; divisor++)
        if (candidato % divisor == 0)
            return false;
    
    return true;
}

int main(int argc, const char **argv){
    
    int primo[N];
    
    for (int encontrados=0, este_numero=2; encontrados<N; este_numero++){
        
        if (es_primo(este_numero)){
            
            primo[encontrados++] = este_numero;
        }
    }
    
    for (int i=0; i<N; i++){
        printf(" %i", primo[i]);
        sleep(1);
    }
    
    printf("\n");
    
    
    
    
    
    return EXIT_SUCCESS;
}
