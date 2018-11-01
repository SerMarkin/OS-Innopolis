
#include <stdio.h>
#include <unistd.h>

int main() {
    int buf_size = 6;
    setvbuf(stdout, NULL, _IOLBF, buf_size);
 
    printf("H");
    sleep(1);

    printf("e");
    sleep(1);

    printf("l");
    sleep(1);

    printf("l");
    sleep(1);
    
    printf("o\n");
    sleep(1);   

    return 0;
}