#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]){
    char f[255] = "";
    char b;
    int fd;

		   printf(argv);

   if (argc>2){
       if (strcmp(argv[1], "-a")==0){
           strcpy(f, argv[2]);
		   printf(f);
           fd = open(f, O_RDWR|O_APPEND);
       }
   }else{
       strcpy(f, argv[1]);
       fd = open(f, O_WRONLY);}
       while (read(STDIN_FILENO, &b, 1) > 0) {
          write(fd, &b, 1);
    }
}