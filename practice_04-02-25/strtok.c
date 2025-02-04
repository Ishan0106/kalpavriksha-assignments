#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char s[] = "This is my house";
    char d[] = " ";

    char *portion = strtok(s,d);
    while(portion != NULL){
        printf("%s\n",portion);
        portion = strtok(NULL,d);
    }
}

