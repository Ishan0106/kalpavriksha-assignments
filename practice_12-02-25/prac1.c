#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void createnode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }
    else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void removenode(int k,int n){
    if(k == n){
        struct node* del = head;
        head = head->next;
        free(del);
        return;
    }
    int start = 0;
    struct node* temp = head;
    for(start=1 ; start < n-k ; start++){
        temp = temp->next;
    }
    struct node* t = temp->next;
    temp->next = t->next;
    free(t);
}

void printLL(){
    struct node* mov = head;
    while(mov != NULL){
        printf("%d->",mov->data);
        mov = mov->next;
    }
    printf("NULL\n");
}

int main(){
    int n,k,i,p;
    printf("enter the number of nodes for LL\n");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        int val;
        scanf("%d",&val);
        createnode(val);
    }
    printf("enter the kth value to remove\n");
    scanf("%d",&p);
    if(p > n){
        printf("not possible to remove\n");
        return 1;
    }
    printf("Linked list before removal\n");
    printLL();
    removenode(p,n);
    printf("Linked list after removal\n");
    printLL();
    return 0;
}
