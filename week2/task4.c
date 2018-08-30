#include <stdio.h>
void swap1(int *a,int *b){
	int c = *a;
	*a = *b;
	*b = c;
}
int main() {
	int n,m;
    	scanf("%d %d", &n, &m); 
	swap1(&n,&m);
	printf("%d %d\n",n,m);
	return 0;
}
