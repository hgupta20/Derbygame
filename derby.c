/* buffer.h */
typedef int buffer_item;
#define BUFFER_SIZE 5

/* main.c */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
//#include "buffer.h"

#define RAND_DIVISOR 100000000
#define TRUE 1

int x=0;


void *function(void *num) {
	int i=0;
    int *myid = (int *)num;
    static int s = -1; 
    printf("Horse %d starts\n", ++s);
    
    //for(i=0; i<100000; i++){
        //x = x+1;
    //}
}


int main(int argc, char *argv[]) {

    /* Create threads */
    int num = 0;
    pthread_t thread_id[20];
    
    printf("3, 2, 1 .. GO!\n");
    for(int i = 0; i < 20; i++) {
        /* Create the thread */
        pthread_create(&thread_id[i],NULL,function,(void *)&num);
    }
    
    for(int i = 0; i < 20; i++) {
        /* Create the thread */
        pthread_join(thread_id[i], NULL);
    }
    //pthread_join(thread_id[0], NULL);
    //pthread_join(thread_id[1], NULL);
    //pthread_join(thread_id[2], NULL);
    //pthread_join(thread_id[3], NULL);
    //pthread_join(thread_id[4], NULL);

    //printf("After x - %d\n", x);
    int lap = 0;
    int horse = 0;
    int lane = 0;
    int position = 0;
    int flag = 0;
    while(lap != 1){
        horse = (rand() % (19 - 0 + 1))  + 0;
        lane = (rand() % (19 - 0 + 1))  + 0;
        
        if (position == 1250){
            lap = 1;
            for (int i = 0 ; i< 20 ; i++){
                lane = (rand() % (19 - 0 + 1))  + 0;
                printf("Horse: %d, Lane: %d, Position: %d, Lap: %d\n",i, lane, position, lap);
            }
            
            printf("The race finishes!\n");
            break;
        }
        printf("Horse: %d, Lane: %d, Position: %d, Lap: %d\n",horse, lane, position++, lap);
        flag++;


    }

    /* Exit the program */
    //printf("Exit the program\n");
    exit(0);
}