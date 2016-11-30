//
//  server.cpp
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

int reading (int client_socket){
    
    do{
        int lenght;
        char *txt;
        int exit = 0;
        
        //--------------------------------/*Leer el msj del socket, si devuelve 0 cliente cierra/
        if(read(client_socket, &lenght, sizeof(lenght)) == 0)
            return 0;
        
        //--------------------------------Reservamos espacio para el msj
        txt = (char*)malloc(lenght);
        read(client_socket, txt, lenght);
        printf("%s", txt);
        
        //---------------------------------Si el msj es exit, salimos
        if(!strcmp(txt, "exit"))
            exit = 1;
        free(txt);
        if(exit)
            return 1;
    }while(1);
    
}

int main (int argc, char *argv[]){

    const char * const socket_name = argv[1];
    struct sockaddr_un name;
    
    //------------------------------------------//Creamos el socket
    int socket_fd = socket(AF_LOCAL, SOCK_STREAM, 0);
    
    //------------------------------------------/*Ponemos en los campos
                                                //.sun_family-->en local
                                                //.sun_path-->nombre del socket*
    name.sun_family = AF_LOCAL;
    strcpy(name.sun_path, socket_name);
    
    //-------------------------------------------//Hacemos bind() al socket
    bind(socket_fd, (struct sockaddr *)&name, SUN_LEN(&name));
    //-------------------------------------------//Poner el socket a listen()
    listen(socket_fd, 5);
    
    do{
        struct sockaddr_un client_name;
        socklen_t client_lenght ;
        
        //-----------------------------------//Aceptas, y se crea un nuevo socket fd de cliente
        int client_socket_fd = accept(socket_fd, (struct sockaddr *)&client_name, &client_lenght);
        
        reading(client_socket_fd);
        close(client_socket_fd);
        
    }while(1);
    
    close(socket_fd);
    unlink(socket_name);
    
    return EXIT_SUCCESS;
    
    
}
