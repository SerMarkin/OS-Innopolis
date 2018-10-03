#include <stdio.h>
#include <stdlib.h>

int main(){
	size_t n = 0;
	printf("N =");
	scanf("%d",&n);
	if (n < 1){
		printf("ERROR");
	}
	int* ar = malloc(n* sizeof(int));
	for (int i = 0 ; i < n; i++)
		ar[i] = i;
	for (int i = 0 ; i < n; i++)
		printf("%d ",ar[i]);
	free(ar);
	return 0;

}
