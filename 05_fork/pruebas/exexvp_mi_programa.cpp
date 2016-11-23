//
//  exexvp_mi_programa.cpp
//  
//
//  Created by Roberto Betés on 27/10/16.
//
//



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void spawn (const char *command, char *args[]){
    
    pid_t hijo_id = fork();
    
    if(!hijo_id){
        execvp (command, args);
        fprintf (stderr, "Vaya, algo ha fallado...\n");
    }
}

int main (int argc, char *argv[]){
    
    int salida;
    
    char *my_program[] = {
        "./",//Directorio actual
        "3",
        "2",
        NULL
    };
    
    spawn("./sumalo",my_program);
    
    printf("Esperando a mi hijo...\n");
    wait(&salida);
    printf("Game-Over\n");
    
    return 0;
}
