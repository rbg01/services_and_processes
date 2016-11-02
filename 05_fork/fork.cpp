//
//  fork.cpp
//
//  Usar fork() para duplicar el proceso de un programa
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
    
    if((child_id =! 0)){
    
        printf("Estás en padre, con id: %i\n", getpid());
        printf("La id del hijo es: %i\n", (int)child_id);
    }
    else{
        printf("con un poco de suerte me la comen, with id: %i\n", getpid());
    }
    
    return 0;

}
