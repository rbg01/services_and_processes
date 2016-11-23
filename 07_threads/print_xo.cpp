

/*	Creación de un hilo	*/
/*	el hilo imprime 'X' */
/*	y main imprime 'O' */

#include <stdio.h>
#include <pthread.h>


void* print_xs(void* unused){

	while(1)
		fputc('X', stderr);

	return NULL;
}

int main(){

	pthread_t thread_id;

	/*Crear un nuevo hilo que llamará a la función "print_xs"*/
	pthread_create (&thread_id, NULL, &print_xs, NULL);

	/*Print 'o' contínuamente por stderr*/
	while(1)
		fputc('O', stderr);

	return 0;
}
