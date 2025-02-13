#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  

void* thread_function(void* arg) {
    printf("Thread started\n");
    sleep(2);  
    printf("Thread exiting\n");
    return NULL;  
}

int main() {
    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0) {
        perror("Thread creation failed");
        return 1;
    }
    printf("Main thread sleeping for 1 second\n");
    sleep(1);  
    pthread_join(thread_id, NULL);
    printf("Main thread exiting\n");
    return 0;
}
