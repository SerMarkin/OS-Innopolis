#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define BUFFER_SIZE 8
#define CURRENT_TIME time(NULL)
#define BEST_RAND (CURRENT_TIME % BUFFER_SIZE)
int flag1=1,flag2=1;
int count = 0;
pthread_cond_t bufFull, bufEmpty;
void* producer(void* a){
	while (1) {
        if (count >= BUFFER_SIZE) {
        	if (flag1)
            	printf("Producer sleeps\n");
            flag1 = 0;
            continue;

        }
        flag1 = 1;
        printf("New item -> %d\n", count+1);
        count = count + 1;
        if (count == 1) {
            printf("Wake up consumer\n");
            pthread_cond_signal(&bufFull);
        }
        sleep(1);
    }
}
void* consumer(void* a){
	while (1) {
        if (count <= 0) {
        	if (flag2)
            	printf("Consumer sleeps\n");
            flag2 = 0;
            continue;

        }
        flag2 = 1;
        printf("Take item -> %d\n", count);
        count = count - 1;
        if (count == BUFFER_SIZE - 1) {
            printf("Wake up producer\n");
            pthread_cond_signal(&bufEmpty);
        }
		sleep(2);
    }
}
int main(int argc, int *argv[]){
    pthread_t thr_c,thr_p;

    pthread_cond_init(&bufFull, 0);
    pthread_cond_init(&bufEmpty, 0);

    pthread_create(&thr_p, NULL, producer, NULL);
    pthread_create(&thr_c, NULL, consumer, NULL);

    pthread_join(thr_p, 0);
    pthread_join(thr_c, 0);

    pthread_cond_destroy(&bufFull);
    pthread_cond_destroy(&bufEmpty);
    return 0;
}