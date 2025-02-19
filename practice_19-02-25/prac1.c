#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void createnode(struct node** head,int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(*head == NULL){
        *head = newnode;
    }
    else{
        struct node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(struct node** head){
    struct node* temp = *head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

struct node* merge(struct node* head,struct node* second){
    if(head == NULL){
        return second;
    }
    if(second == NULL){
        return head;
    }
    if(head->data < second->data){
        head->next = merge(head->next,second);
        return head;
    }
    else{
        second->next = merge(head,second->next);
        return second;
    }
}

struct node* split(struct node* head){
    if(head == NULL){
        return NULL;
    }
    struct node* slow = head;
    struct node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct node* temp = slow->next;
    slow->next = NULL;
    return temp;
}

struct node* mergesort(struct node** head){
    if(*head == NULL){
        return NULL;
    }
    if((*head)->next == NULL){
        return *head;
    }
    struct node* second = split(*head);
    mergesort(head);
    mergesort(&second);
    *head = merge(*head,second);
    return *head; 
}

int main(){
    struct node* head = NULL;
    createnode(&head,40);
    createnode(&head,30);
    createnode(&head,20);
    createnode(&head,10);
    display(&head);
    head = mergesort(&head);
    display(&head);
}
