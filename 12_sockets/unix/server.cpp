//
//  server.cpp
//  
//
//  Created by Roberto Betés on 24/11/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>

void talk_to(int pipe){
    
    
}

int main (int argc, char *argv[]){
    
    struct sockaddr_un socket_filedata;
    socket_filedata.sun_family = AF_LOCAL;  //-->le decimos q la direccion va a ser local, que son nombres de ficheros
    strcpy (socket_filedata.sun_path, argv[1]);     //-->le decimos dnd está
    
    int socket_fd = socket(PF_UNIX, SOCK_STREAM, 0);
    //SUN_LEN --> Socket Unix Lenght
    bind (socket_fd, &socket_filedata, SUN_LEN(&socket_filedata));
    listen(socket_fd, 5);//-->cola de 5 peticiones simultáneas
    
    do{
        struct sockaddr_un who_are_you;
        socklen_t who_lenght_you;
        //a partir de aqui aaccept conexiones
        int new_connection_fd = accept(socket_fd, &who_are_you, &who_lenght_you);
        talk_to(new_connection_fd);
        close(new_connection_fd);
        
    }while(1);
    
    close(socket_fd);
    unlink(argv[1]);
    return EXIT_SUCCESS;
}
