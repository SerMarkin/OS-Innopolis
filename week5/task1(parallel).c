#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void* printN(void *tid){
	int n =(int)tid;
	printf("Start %d\n",n);
	printf("Something Something Something Something Something %d\n",n);
	printf("End %d\n",n);
	pthread_exit(0);
}
int main(int argc, int *argv[]){
    int n = 10,status;
    pthread_t thread[n];
    for (int i = 0; i< n;i++){
    	status = pthread_create(&thread[i],NULL,printN,(void *)i);
	}
    for (int i = 0; i< n;i++){
       pthread_join(thread[i],NULL);
    }
    return 0;
}