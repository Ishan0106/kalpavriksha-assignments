#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){
    fork();
    fork();
    fork();
    printf("Hello there, PID = %d\n",getpid());
    return 0;
}
