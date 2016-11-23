//
//  semaphores.cpp
//  
//
//  Created by Roberto Betés on 16/11/16.
//
//



#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

sem_t *semaforo;

void *print(void *parameter)
{
    
    char *caracter = (char *) parameter;
    
    
    for (int i = 0; i < 10; i++) {
        printf("Hilo 1: %i \n", i);
         sleep(1);
    }
    printf("Antes del post %i\n", semaforo);
    sem_post(semaforo);
    printf("Despues del post %i\n", semaforo);
    return NULL;
}

void *printxx(void *parameter)
{
    char *caracter = (char *) parameter;
   
    
   
    printf("Antes del wait %i\n", semaforo);
    sem_wait(semaforo);
      printf("Despues del wait %i\n", semaforo);
    for (int i = 0; i < 10; i++) {
        printf("Hilo 2: %i \n", i);
        sleep(1);
    }
    
    return NULL;
}

int main(int argc, char const *argv[]) {
    pthread_t thread_id1, thread_id2;
    char x = 'x';
    char o = 'o';
    //const char smfr = 'semaforo';
    
    if ((semaforo = sem_open (argv[0], O_CREAT, 0644, 0 )) == SEM_FAILED){
        fprintf(stderr, "No se ha podido crear el semaforo.\n");
        return 1;
    }
    printf("%s %s\n", argv[0], argv[1]);
    pthread_create (&thread_id1, NULL, &print, &x);
    pthread_create (&thread_id2, NULL, &printxx, &o);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    
    printf("\n");
    sem_close(semaforo);
    
    return 0;
}
