#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>


#define path1 "ex4_1.txt"
#define path2 "ex4_2.txt"


int main() {
	int fd1 = open(path1, O_RDONLY);
	int fd2 = open(path2, O_RDWR);
	struct stat st1;
	stat(path1, &st1);
	truncate(path2,st1.st_size);
	char *f1=(char*)mmap(0,st1.st_size,PROT_READ,MAP_SHARED,fd1,0);
	char *f2=(char*)mmap(0,st1.st_size,PROT_READ|PROT_WRITE,MAP_SHARED, fd2,0);
	memcpy(f1,f2,st1.st_size);
	munmap(f1, st1.st_size);
	munmap(f2, st1.st_size);
	close(fd1);
	close(fd2);
	return 0;
}