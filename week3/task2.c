#include <stdio.h>
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Buble_sort(int *ar,int n){
	for (int i = 0; i< n;i++){
		for (int j = 1; j< n-i;j++){
			if (ar[j]<ar[j-1]){
				swap(&ar[j],&ar[j-1]);
			}
		}
	}
	return;
}
int main(){
 int p= 1,c=2;
 int ar[10] = {4,2,6,98,6,4,3,2,5,7};
Buble_sort(&ar,10);
for (int i =0;i<10;i++){
	printf("%d ", ar[i]);
}
 return 0;
}
