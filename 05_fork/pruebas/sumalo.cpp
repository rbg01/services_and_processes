//
//  sumalo.cpp
//  
//
//  Created by Roberto Betés on 27/10/16.
//
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv){


    int op1 = 0;
    int op2 = 0;
    
    if(argc == 1)
        printf("...¡¡Warning!!....\n"
               "ingresa dos números\n");
    
    op1 = atoi(argv[1]);
    op2 = atoi(argv[2]);
    
    printf ("%i + %i = %i\n", op1, op2, op1 + op2);
    
    return EXIT_SUCCESS;

}
