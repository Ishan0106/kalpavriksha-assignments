// queue using LL

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    struct node* next;
}node;

void enque(node** front,node** rear,int val){
    node* new = (node*)malloc(sizeof(node));
    new->data = val;
    new->next = NULL;
    if(*rear == NULL){
        *rear = new;
        *front = new;
    }
    else{
        (*rear)->next = new;
        *rear = (*rear)->next;
    }
}

void deque(node** front){
    node* temp = *front;
    *front = (*front)->next;
    temp->next = NULL;
    free(temp);
}

void display(node** front,node** rear){
    node* temp = *front;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}

int main(){
    node* front = NULL;
    node* rear = NULL;
    int choice;
    do{
        printf("1.enque\n");
        printf("2.deque\n");
        printf("3.display\n");
        printf("enter choice\n");
        scanf("%d",&choice);
        if(choice == 1){
            int value;
            scanf("%d",&value);
            enque(&front,&rear,value);
        }
        else if(choice == 2){
            deque(&front);
        }
        else if(choice == 3){
            display(&front,&rear);
        }
    }while(choice != 4);
}