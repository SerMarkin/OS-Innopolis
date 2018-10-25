#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


int main() {
	DIR *tmp = opendir("tmp");
	struct dirent *dir=readdir(tmp);	
	struct stat statdat;
	char fpath[64];
	char command[128];
	while (dir != NULL) {
		if (dir->d_name[0] != '.') {
			sprintf(fpath,"./tmp/%s",dir->d_name);
			stat(fpath,&statdat);
			if (statdat.st_nlink >= 2) {
				printf("Links for %s\n",dir->d_name );
				sprintf(command, "find -inum %lu", statdat.st_ino);
				system(command);
			}
		}
		dir=readdir(tmp);
	}
}
