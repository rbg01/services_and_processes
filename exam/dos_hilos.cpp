//
//  dos_hilos.cpp
//  
//
//  Created by Roberto Betés on 5/11/16.
//
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

bool es_primo(int candidato){
    
    for (int divisor=2; divisor<candidato; divisor++)
        if (candidato % divisor == 0)
            return false;
    
    return true;
}


void *print_crono(void *parameter){
    
    int numero = *((int*)parameter);
    
    int hours, mins, secs;
    
    for(hours = 0; hours < 100;hours++){
        
        for(mins = 0; mins < numero; mins++){
            
            for(secs = 0; secs < numero; secs++){
                
                fprintf(stdout, "%i:%i:%i\n",hours, mins, secs);
                sleep(1);
                fflush(stdout);
                
            }
        }
    }

    return NULL;
    
}

void *print_primos(void *parameter){
    
    int numero = *((int*)parameter);
    
    int primo[numero];
    
    for (int encontrados=0, este_numero=2; encontrados<numero; este_numero++){
        
        if (es_primo(este_numero)){
            
            primo[encontrados++] = este_numero;
        }
    }
    
    for (int i=0; i<numero; i++){
        fprintf(stderr," %i\n", primo[i]);
        sleep(1);
        fflush(stderr);
    }

    return NULL;
    
}


int main(int argc, const char **argv){
    
    pthread_t thread_crono, thread_primos;
    
    int argument = 60;
    pthread_create(&thread_primos, NULL, &print_primos, &argument);
    pthread_create(&thread_crono, NULL, &print_crono, &argument);
    
    pthread_join(thread_crono, NULL);
    pthread_join(thread_primos, NULL);
    
    return 0;
    
}
