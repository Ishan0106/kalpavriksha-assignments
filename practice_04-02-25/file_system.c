#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct node{
    char *str;
    struct node *next;
};

int main(){
    struct node* front = NULL;
    struct node* rear = NULL;
    char str[MAX];
    int N = 4;
    while(N--) {
        printf("Enter a string (type 'exit' to quit): ");
        scanf(" cd %s",str);
        if(strcmp(str,"../") == 0){
            struct node* prev = NULL;
            struct node* cur = front;
            while(cur->next != NULL){
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            free(cur);
            rear = prev;
        }
        else if(strcmp(str,"./") == 0){
            continue;
        }
        else{
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            temp->str = (char*)malloc(strlen(str) + 1);  
            strcpy(temp->str, str);
            temp->next = NULL;
            if(rear == NULL){
                front = rear = temp;
            }else{
                rear->next = temp;
                rear = rear->next;
            }
        }
    }
    printf("/");
    struct node* t = front;
    while(t != NULL){
        printf("%s",t->str);
        t = t->next;
    }
    return 0;
}