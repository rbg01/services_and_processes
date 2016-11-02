//
//  fork_01.cpp
//  
//
//  Created by Roberto Betés on 2/11/16.
//
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    
    pid_t child_id;
    
    printf("La id de main() es: %i\n", getpid());
    
    child_id = fork();
    
    if(child_id == 0){
        
        printf("Estás en hijo, con id: %i\n", (int)child_id);
        printf("La id del padre es: %i\n",getpid()) ;
    }
    else{
        printf("sigues en el padre, with id: %i\n", getpid());
    }
    
    return 0;
    
}
//
//Produce la salida:
//La id de main() es: 1903
//sigues en el padre, with id: 1903
//Estás en hijo, con id: 0
//La id del padre es: 1904
//
//
//
//
