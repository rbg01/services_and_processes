
  /*  COMANDO  system*/
#include <stdlib.h>

int main(){

    int return_value;

    return_value = system("open -a /Applications/Firefox.app");

    return return_value;
}
