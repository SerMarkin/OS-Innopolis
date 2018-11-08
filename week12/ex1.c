#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    int fr = open("/dev/random", O_RDONLY);

    char bf[20];
    read(fr, bf, 20);
	printf("%s\n",bf);
}