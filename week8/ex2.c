#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(){
  for(int i=0; i < 10; i++){
    void* byte1 = malloc(10*1024*1024);
    byte1 = memset(byte1, 0, 10*1024*1024);
    sleep(1);
  }
	return 0;
}
