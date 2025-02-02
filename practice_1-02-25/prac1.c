#include<stdio.h>
#include<stdlib.h>

struct Node{
    int c;
    int p;
    struct Node *next; 
};

struct Node *head1 = NULL;
struct Node *head2 = NULL;
struct Node *result = NULL;

void createNode1(int coe , int power){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->c = coe;
    newNode->p = power;
    newNode->next = NULL;
    if(head1 == NULL){
        head1 = newNode;
    }
    else{
        struct Node* temp = head1;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void createNode2(int coe , int power){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->c = coe;
    newNode->p = power;
    newNode->next = NULL;
    if(head2 == NULL){
        head2 = newNode;
    }
    else{
        struct Node* temp = head2;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void createNode3(int coe , int power){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->c = coe;
    newNode->p = power;
    newNode->next = NULL;
    if(result == NULL){
        result = newNode;
    }
    else{
        struct Node* temp = result;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


int main(){
    int n1 , n2;
    printf("enter number of terms for polynomial one\n");
    scanf("%d",&n1);
    for(int i = 0 ; i < n1 ; i++){
        int coe , power;
        if(coe == 0){
            continue;
        }
        scanf("%d %d",&coe,&power);
        createNode1(coe,power);
    }
    printf("enter number of terms for polynomial two\n");
    scanf("%d",&n2);
    for(int i = 0 ; i < n2 ; i++){
        int coe , power;
        if(coe == 0){
            continue;
        }
        scanf("%d %d",&coe,&power);
        createNode2(coe,power);
    }

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    while(p1 != NULL && p2 != NULL){
        if(p1->p > p2->p){
            int coe = p1->c;
            int power = p1->p;
            createNode3(coe,power);
            p1 = p1->next;
        }
        else if(p2->p > p1->p){
            int coe = p2->c;
            int power = p2->p;
            createNode3(coe,power);
            p2 = p2->next;
        }
        else if(p1->p == p2->p){
            int coe = p1->c + p2->c;
            int power = p1->p;
            createNode3(coe,power);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    struct Node* ptr = result;
    while(ptr != NULL){
        printf("%dX^%d + ",ptr->c,ptr->p);
        ptr = ptr->next;
    }
    return 0;
}
