#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[100] = "add(ishan,10)|add(harsh,20)";
    char* token;
    token = strtok(str,"|");
    while(token != NULL){
        char name[100];
        int age;
        sscanf(token,"add(%[^,],%d)",name,&age);
        printf("name:%s , age:%d\n",name,age);
        token = strtok(NULL,"|");
    }
    if(strncmp(str,"add",3) == 0){
        printf("true");
    }
}