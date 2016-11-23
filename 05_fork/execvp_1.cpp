

    /*  Uso de execvp */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, const char *argv[]){

    pid_t hijo_pid;

    char *my_program[] = {

        "-a",
        "/Applications/FaceTime.app",
        NULL
    };

    hijo_pid = fork();

    if(hijo_pid == 0){

        execvp("open", my_program);
        printf("Esto no se ejecuta normalmente...\n");
    }

    printf("si ves ésto, es que main() está acabado\n");


	return EXIT_SUCCESS;
}
