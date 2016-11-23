#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[]){

  Vector v1 = {1, 2, 3},
         v2 = {2, -1, 3};

  print(cross(v1, v2));
  




	return 0;
}
