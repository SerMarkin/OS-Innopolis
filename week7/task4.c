#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

void* myrealloc(int* ptr,size_t t){
	int *ar;
	if(t == 0 ){
		free(ptr);
		return ptr;
	}
	if(ptr == NULL){
		ar = malloc(t);
		printf("ptr is NULL\n");
	}else{
	        ar = malloc(t);
	        memcpy(ar, ptr, t);
	        free(ptr);
	}

  	return ar;
}

int main(){
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* ar1 = malloc(n1* sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		ar1[i]=100;
		
		//Print each element out (to make sure things look right)
		printf("%d ",ar1[i] );
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	ar1 = myrealloc(ar1,n2* sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

	for (int i = n1; i<n2;i++){
		ar1[i] = 0;				
	}	
	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ",ar1[i]);
	}
	printf("\n");
	
	//Done with array now, done with program :D
	
	return 0;
}
