//
//  dupdos_ussage.cpp
//  
//
//  Created by Roberto Betés on 23/11/16.
//
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (int argc, char *argv[]){
    
    int fds[2];     //Array file descriptors para los extremos del pipe
    pid_t pid;
    
    //creamos pipe y ponemos los file descriptors para los extremos del pipe, en fds
    pipe(fds);
    
    //forkeamos un proceso hijo
    pid = fork();
    if (pid == (pid_t)0){
        //estamos en hijo
        //y cerramos file descriptor write
        close(fds[1]);
        //Conectamos el read end del pipe al stdin
        dup2 (fds[0], STDIN_FILENO);
        //Abrimos sort
        execlp("sort", "sort", 0);
    }else{
        //Proceso padre
        FILE *stream;
        //Cerramos el write end del file descriptor
        close(fds[0]);
        stream = fdopen(fds[1], "w");
        fprintf(stream,"This is a test.\n");
        fprintf(stream,"Hello,Porld.\n");
        fprintf(stream,"My dog has fleas.\n");
        fprintf(stream,"This program is full.\n");
        fprintf(stream,"One thing, two, things, my 33 balls\n");
        fflush(stream);
        close(fds[1]);
        
        //hacemos un wait al hijo
        waitpid(pid, NULL, 0);

    }
    return 0;
    
}
