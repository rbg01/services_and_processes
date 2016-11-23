
//
//  sem_create.cpp
//
//
//  Created by Roberto Betés on 16/11/16.
//
//
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define PROGNAME "sem_create"

void CHECK_ARGS(count, msg) {
    
    if(argc != count){
        fprintf(stderr,"usage: %s" msg "\n", PROGNAME);
        exit(1);
    }


int main (int argc, char **argv){
    
    int val;
    sem_t * semaphore;
    
    CHECK_ARGS (3, "<path> <value>");
    
    val = atoi(argv[2]);
    
    semaphore = sem_open (argv[1], O_CREAT | O_EXCL, 0644, val);
    if (semaphore == (sem_t *)SEM_FAILED){
        perror("sem_open");
        exit(1);
    }
    
    sem_close(semaphore);
    
    exit(0);
    
}
