//
//  print_struct.cpp
//  
//
//  Created by Roberto Betés on 26/10/16.
//
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct Tparameter{
    
    char caracter;
    int veces;
};



void* print_xs(void* parameter){
    
    struct Tparameter *datos = (struct Tparameter *) parameter;
    
    for(size_t i = 0; i < datos->veces; i++)
        fputc(datos->caracter, stderr);
    
    
    return NULL;
}


int main(){
    
    
    pthread_t thread_para_meter1, thread_para_meter2;
    struct Tparameter para_meter1 = {'X', 500};
    struct Tparameter para_meter2 = {'O', 500};
       
        pthread_create (&thread_para_meter1, NULL, &print_xs, &para_meter1);
        pthread_join(thread_para_meter1, NULL);
        pthread_create (&thread_para_meter1, NULL, &print_xs, &para_meter2);
        pthread_join(thread_para_meter1, NULL);
    
    
    return 0;
}
