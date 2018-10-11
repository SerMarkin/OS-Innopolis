#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

int main(){
    struct rusage usage;
  for(int i=0; i < 10; i++){
    void* byte1 = malloc(10*1024*1024);
    byte1 = memset(byte1, 0, 10*1024*1024);
    struct rusage *usage = malloc(sizeof(struct rusage));
    getrusage(RUSAGE_SELF, usage);
    printf("Memory: %lu\n", usage->ru_maxrss);
    sleep(1);
  }

	return 0;
}
