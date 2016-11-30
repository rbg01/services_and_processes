//
//  client.cpp
//  
//
//  Created by Roberto Betés on 29/11/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

void writting(int socket_fd, const char* text){
    
    int lenght = strlen(text) + 1;
    write(socket_fd, &lenght, sizeof(lenght));
    write(socket_fd, text, lenght);
}


int main (int argc, char *argv[]){

    const char * const socket_name = argv[1];
    const char * const msj = argv[2];
    //------------------------------------------/*//struct sockaddr_un-->tiene dos campos
                                                //.sun_family-->SOCKET UNIX FAMILY
                                                //.sun_path-->EL PATH DEL SOCKET*/
    struct sockaddr_un name;
    
    //------------------------------------------//Creamos el socket
    int socket_fd = socket(AF_LOCAL, SOCK_STREAM, 0);
    
    //------------------------------------------/*Ponemos en los campos
                                                //.sun_family-->en local
                                                //.sun_path-->nombre del socket*/
    name.sun_family = AF_LOCAL;
    strcpy(name.sun_path, socket_name);
    
    //------------------------------------------//Conectamos al socket
    connect(socket_fd, (struct sockaddr *)&name, SUN_LEN(&name));
    
    writting(socket_fd, msj);
    close(socket_fd);
    
    return EXIT_SUCCESS;
    

}
