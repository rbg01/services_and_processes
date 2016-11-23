//
//  pipes_txe.cpp
//  
//
//  Created by Roberto Betés on 22/11/16.
//
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void writer(const char *mssg, int times, FILE *stream_out){
    
   
    const char *letter;
    
    for(letter=mssg; times>0; --times, letter=mssg)
        while(*letter != '\0'){
            fputc(*letter, stream_out);
            fputc(*letter, stderr);
            fflush(stream_out);
            letter++;
            usleep(100000);
        }
    
}

void reader(FILE *stream_in){
    
    char c;
    
    while(!feof(stream_in) && !ferror(stream_in) && (c=fgetc(stream_in))){
        fputc(c, stdout);
        fputc('\a', stdout);
        fflush(stdout);
    }
    
}

int main(int argc, char *argv[]){
    
    int fds[2];
    pid_t pid;
    
    if(pipe(fds) == -1){
        fprintf(stderr, "pipe invoked FAILED..\n");
        return EXIT_FAILURE;
    }

    
    pid = fork();
    /*
    if(pid == (pid_t) 0){
    
        close(fds[1]);
        reader(fdopen(fds[0], "r"));
        close(fds[0]);
    }else{
        close(fds[0]);
        writer("World is a vampire\n", 5,fdopen(fds[1], "w"));
        close(fds[1]);
    }
   */
    
   
    if(pipe(fds) == -1){
        fprintf(stderr, "pipe invoked FAILED..\n");
        return EXIT_FAILURE;
    }

    
    pid = fork();
    //if(!pid){
    if (pid == (pid_t) 0) {
        close(fds[0]);
        writer("World is a Vampire\n", 5, fdopen(fds[1], "w"));
        close(fds[1]);
    } else {
        close(fds[1]);
        reader(fdopen(fds[0], "r"));
        close(fds[0]);
    }
    
    
    return EXIT_SUCCESS;
}

