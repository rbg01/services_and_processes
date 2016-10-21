

  /*  Uso de fork y execvp juntos*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int spawn (const char *program, char **arg_list){

    pid_t child_pid;

    //Duplicar el proceso
    child_pid = fork();
    if (child_pid != 0)
        //Estamos en el proceso padre
        return 0;
    else {
        execvp (program, arg_list);
        //execvp solo devuelve un valor si ha habído fallo
        fprintf (stderr, "ha habído algún error en execvp....\n");
        abort();
    }

}

int main(int argc, char *argv[]){
  
    int salida;
    spawn("ls", argv);

    printf("Hecho a través del main\n");

    wait(&salida);
    printf("Game over.\n");


	return 0;
}
