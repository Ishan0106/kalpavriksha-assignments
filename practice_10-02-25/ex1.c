#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[]){
    printf("PID of ex1.c = %d\n",getpid());
    char *args[] = {"ls", NULL};
    execvp("ls",args);
    perror("execv failed\n");
    printf("Back to ex1.c\n");
    return 0;
}
