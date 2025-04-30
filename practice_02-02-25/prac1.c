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

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int n,k;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        int value;
        scanf("%d",&value);
        createNode(value);
    }
    printList(head);

    printf("enter the value of k\n");
    scanf("%d",&k);
    struct Node* temp = head;
    struct Node* dummy = NULL;
    int cnt = 1;
    while(temp != NULL){
        if(cnt % k == 0){
            struct Node* t = temp;
            dummy->next = temp->next;
            temp = dummy->next;
            free(t);
            cnt++;
        }else{
            dummy = temp;
            temp = temp->next;
            cnt++;
        }
    }
    printList(head);
    return 0;
}
