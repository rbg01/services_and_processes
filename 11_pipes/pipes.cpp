//
//  pipes.cpp
//  
//
//  Created by Roberto Betés on 22/11/16.
//
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//Escribe COUNT copias del msj al strea, y para un seg entre cada una
void writer(const char* message, int count, FILE* stream){

    for(; count > 0; --count){
        //Escribimos el mensaje en el stream, y hacemos fflush inmediatamente
        /*fprinf(*stream, "%formato", _tipoformato)-->como prntf
         If successful, the total number of characters written is returned otherwise, a negative number is returned.*/
        fprintf (stream, "%s\n", message);
        fflush(stream);
        sleep(1);
    }
}

//Lee cadenas aleatorias del stream lo mas largas posibles
void reader(FILE* stream){

    char buffer[1024];
    //lee hasta que llega el final del fichero. fgets lee ya sea una nuevo linea o EOF
    while(!feof (stream)
          && !ferror (stream)
          /*fgets(char * buffer, int size, FILE * restrict stream) lee carcteres del stream, tantos como indica size, y los guarda en el string buffer. la lectura para cuando encuentra un caracter de nueva linea en end of file
           o un error. Coloca '\0' al final del string*/
          && fgets(buffer, sizeof(buffer), stream) != NULL)
        /*fputs(const char * s, FILE * stream)pone la cadena *s,
         en el *stream*/
        fputs(buffer, stdout);
}

int main (){
    
    int fds[2]; //Identificadores de file descriptor
    pid_t pid;
    
    //crear una pipe, los finales de los file descriptor los situamos en fds
    pipe(fds);
    
/*  Cuando llamo a pipe(fds) almacena el reading file descriptor;
     read_fd = fds[0] //file_descriptor 0
    y el writing file descriptor
     write_fd = fds[1] //file_descriptpor 1
 */
    
    //forkeamos
    pid = fork();
    
    if(pid == (pid_t) 0){ //Estamos en hijo porq el pid es zero
        
        FILE* stream;
        //Cerramos writing descriptor
        close(fds[1]);
        printf("y una polla como una olla\n");
        /*fdopen asocia un file descriptor y un modo....
         y si todo va bien devuelve un puntero FILE* stream*/
        //abrimos reading descriptor con fdopen en modo "read"
        stream = fdopen(fds[0], "r");
        //Y mandamos a la función reader el puntero
        reader(stream);
        //cerramos el reading descriptor
        close(fds[0]);
       
    }
    else{
        //Estamos en el padre
        FILE* stream;
        //cerramos reading descriptor
        close(fds[0]);
        //abrimos writing descriptor en modo "write"
        stream = fdopen(fds[1], "w");
        //y mnadamos a la función writer el puntero
        writer("Hola cara de nabo...", 5, stream);
        //cerramos el writing descriptor
        close(fds[1]);
        
        
    }
    return 0;
}
