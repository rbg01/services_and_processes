




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, const char *argv[]){

    int hours, mins, secs;
    
    for(hours = 0; hours < 100;hours++){
        
        for(mins = 0; mins < 60; mins++){
            
            for(secs = 0; secs < 60; secs++){
               
                fprintf(stdout, "%i:%i:%i\n",hours, mins, secs);
                sleep(1);
                system("clear");
                fflush(stdout);
               
            }
        }
    }

	return EXIT_SUCCESS;
}
