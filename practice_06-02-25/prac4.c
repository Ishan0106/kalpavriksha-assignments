#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char input[] = "132 13 3 5 34 56";  
    char* token;
    token = strtok(input, " ");  
    while(token != NULL){
        printf("%s ", token); 
        token = strtok(NULL, " ");  
    }
    return 0;
}
