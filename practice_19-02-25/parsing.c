#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[] = "1 2 3 4 56 6 7";
    char* token = strtok(str," ");
    while(token != NULL){
        printf("%s ",token);
        token = strtok(NULL," ");
    }
}