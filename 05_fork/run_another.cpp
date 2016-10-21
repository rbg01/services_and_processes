


    /* Uso de fork y execvp en funcion spawn
     * para abrir facetime    */

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
        "open",
        "-a",
        "/Applications/FaceTime.app",
        NULL
    };

    spawn("open",my_program);

    printf("Esperando a mi hijo...\n");
    wait(&salida);
    printf("Game-Over\n");

    return 0;
}
