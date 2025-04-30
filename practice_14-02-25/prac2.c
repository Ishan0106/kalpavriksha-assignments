#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count1 = 0;
int count2 = 0;
pthread_mutex_t mutex;
//pthread_cond_t not_full;
//pthread_cond_t not_empty;

void* producer(void* arg) {
    while (1) {
        sleep(1);
        
        pthread_mutex_lock(&mutex);

        // while (count1 == BUFFER_SIZE) {
        //     pthread_cond_wait(&not_full, &mutex);
        // }

        buffer[count1] = rand() % 100;
        printf("Produced: %d\n", buffer[count1]);
        count1=(count1+1)%5;

        // pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* consumer(void* arg) {
    while (1) {
        sleep(1);

        pthread_mutex_lock(&mutex);

        // while (count2 == 0) {
        //     pthread_cond_wait(&not_empty, &mutex);
        // }

        int item = buffer[count2];
        count2=(count2+1)%5;
        printf("Consumed: %d\n", item);

        // pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread, prod2_thread;

    pthread_mutex_init(&mutex, NULL);
    // pthread_cond_init(&not_full, NULL);
    // pthread_cond_init(&not_empty, NULL);

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&prod2_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(prod2_thread, NULL);
    pthread_join(cons_thread, NULL);
    

    pthread_mutex_destroy(&mutex);
    // pthread_cond_destroy(&not_full);
    // pthread_cond_destroy(&not_empty);

    return 0;
}
