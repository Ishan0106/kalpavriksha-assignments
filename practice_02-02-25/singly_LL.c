#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createNode(int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
        struct Node* move = head;
        while(move->next != NULL){
            move = move->next;
        }
        move->next = temp;
    }
}

int main(){
    int n;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        int value;
        scanf("%d",&value);
        createNode(value);
    }

    struct Node* temp = head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    return 0;
}