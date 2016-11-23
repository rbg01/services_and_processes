

/*	Creación de 4 hilos	*/
/*	el hilo 1 imprime 'A' */
/*	el hilo 2 imprime 'B' */
/*	el hilo 3 imprime 'C' */
/*	el hilo 4 imprime 'D' */
/*	el hilo 4 imprime 'E' */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void* print_xs(void* parameter){
    
    char *caracter = (char*) parameter;

    for(size_t i = 0; i < 4000; i++)
        fputc(*caracter, stderr);
        
    
	return NULL;
}

int main(){
    
    char parameters[] = {'A','B','C','D', 'E'};

    pthread_t threads[5];
    
       for(int i = 0; i < 5; i++){
        pthread_create (&threads[i], NULL, &print_xs, &parameters[i]);
        pthread_join(threads[i], NULL);
    }
    

	return 0;
}
