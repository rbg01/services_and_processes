
/*	Creación de un hilo */
 /*	el hilo imprime 'X'*/
 /*	y el otro hilo imprime 'O' */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *print(void *parameter)
{
        char *caracter = (char *) parameter;
        for (size_t i = 0; i < 40000; i++) {


                fputc (*caracter, stderr);
        }
        return NULL;
}
int main(int argc, char const *argv[]) {
        {
                pthread_t thread_id1, thread_id2;
                char x = 'x';
                char o = 'o';
                pthread_create (&thread_id1, NULL, &print, &x);
                pthread_create (&thread_id2, NULL, &print, &o);
                pthread_join(thread_id1, NULL);
                pthread_join(thread_id2, NULL);

                printf("\n");
        }
        return 0;
}
