#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
int main() {
    char strp[] = "{{shubh:23},{shreyas:24},{vikas:34}}";
    char* ptr = strp + 2;
    int n = strlen(strp);
    strp[n-2] = '\0'; // Trimming the last '}' character

    char* token = strtok(ptr, "},{");
    while (token != NULL) {
        char name[100]; 
        int num;
        sscanf(token, "%[^:]:%d", name, &num);  // Corrected format specifier and use &num
        printf("%s : %d\n", name, num);
        token = strtok(NULL, "},{");
    }
    return 0;
}
*/
/*
int main(){
    char strp[] = "add(hello,23)|pop()|add(shubh,34)";
    char* token = strtok(strp,"|");
    while(token != NULL){
        if(strncmp(token,"add",3) == 0){
            char name[100];
            int age;
            sscanf(token,"add(%[^,],%d",name,&age);
            printf("push is call with name : %s , age : %d\n",name,age);
        }
        else if(strncmp(token,"pop",3) == 0){
            printf("pop is called\n");
        }
        token = strtok(NULL,"|");
    }
}
*/
int main(){
    char strp[] = "[('John', 25, 'USA'), ('Shubh', 23, 'India'), ('Vikas', 34, 'UK')]";
    char* str = strp+1;
    char name[100];
    int age;
    char loc[100];
    str[strlen(str) - 1] = '\0';
    char* token = strtok(str,")(");
    while(token != NULL){
        printf("%s\n",token);
        sscanf(token,"  '%[^']', %d, '%[^']'",name,&age,loc);
        //printf("name:%s, age:%d, location:%s\n",name,age,loc);
        token = strtok(NULL,")(");
        printf("%s\n",token);
        token = strtok(NULL,")(");
        printf("%s\n",token);
    }
}
