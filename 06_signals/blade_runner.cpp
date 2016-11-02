#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#define N   0x100
#define MAX 0x1000

sig_atomic_t hijo_vivo = 0;

void clean_child(int sig_number) {
    int exit_status;
    
    wait(&exit_status);//wait recoje el retorno de un proceso hijo...y le pasamos la variable &exit_status para recoger el valor
    hijo_vivo = 0;//si no se coge el valor de retorno el proceso se queda zombi
}

void spawn(char *argv[]){
    pid_t child_pid = fork();
    
    if (child_pid) {
        hijo_vivo = 1;
        return;
    }
    
    // Only the child is running.
    execvp(argv[0], argv);
    fprintf(stderr, "%s never was up. Returning.\n", argv[0]);
    abort();
}

int main() {
    int  i = 0;
    char buffer[MAX];
    char *command[N];
    char *parse = buffer;
    
    struct sigaction conf_handler;
    bzero(&conf_handler, sizeof(conf_handler));
    conf_handler.__sigaction_u.__sa_handler = &clean_child;//al campo sa_handler le doy la direccion de mi funcion
    sigaction(SIGCHLD, &conf_handler, NULL);//cada vez q llegue SIGCHILD llama a la funcion
    
    printf("Command: ");
    fgets(buffer, MAX, stdin);
    
    while ( (command[i++] = strtok(parse, " ")) != NULL)
        parse = NULL;
    
    printf("Waiting for %s to end.\n", command[0]);
    //cunado un hijo muere el sistema me manda la señal USERCHILD
    spawn(command);
    
    while (hijo_vivo)
        sleep(1);
        printf("%s is over.\n", command[0]);
    
    
    return EXIT_SUCCESS;
}
