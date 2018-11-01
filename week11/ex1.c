 #include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

#define new_str "This is a nice day"
#define path "ex1.txt"
int main(){
	int msize = 18;
	FILE *ptr;
	unsigned char *f;
	struct stat s;
	int fd = open(path,O_RDWR);
	fstat(fd,&s);
	truncate(path, msize);
	f=(char*) mmap(0,s.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

	for (int i=0;i<msize;i++){
		f[i]=new_str[i];
	}

	munmap(f,msize);
	close(fd);
	return 0;
}