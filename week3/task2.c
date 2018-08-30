#include <stdio.h>
int main() {
	char str[100];
	gets(str);
	for (int i=0;i<strlen(str) ;i++){
		printf("%c",str[strlen(str)-i-1]);
	} 
	return 0;
}
