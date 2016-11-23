//
//  my_blade_runner.cpp
//  
//
//  Created by Roberto Betés on 1/11/16.
//
//





/* Uso de fork y execvp en funcion spawn
 * para abrir facetime   y otra más  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

sig_atomic_t hijo_vivo = 0;

void clean_child(int sig_number) {
    int exit_status;
    
    wait(&exit_status);//wait recoje el retorno de un proceso hijo...y le pasamos la variable &exit_status para recoger el valor
    hijo_vivo = 0;//si no se coge el valor de retorno el proceso se queda zombi
}


void spawn (const char *command, char *args[]){
    
    
    pid_t hijo_id = fork();
   
    
    if (hijo_id) {
        hijo_vivo = 1;
        return;
    }
    
    // Only the child is running.
    execvp(command, args);
    fprintf(stderr, "%s never was up. Returning.\n", command);
    abort();
}

int main (int argc, char *argv[]){
    
    int salida;
        
    char *my_program[] = {
        
        "-a",
        "/Applications/FaceTime.app",
        NULL
    };
    
    struct sigaction conf_handler;
    bzero(&conf_handler, sizeof(conf_handler));
    conf_handler.__sigaction_u.__sa_handler = &clean_child;//al campo sa_handler le doy la direccion de mi funcion
    sigaction(SIGCHLD, &conf_handler, NULL);//cada vez q llegue SIGCHILD llama a la funcion
    
    spawn("open", my_program);
    
    while (hijo_vivo)
        sleep(1);
    
    printf("%s is over.\n", argv[0]);

    
    
    return 0;
}
