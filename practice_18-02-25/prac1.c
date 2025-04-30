// subarrays with exactly k different integers
#include<stdio.h>
#include<stdlib.h>
#define MAX 100


struct node{
    int data;
    struct node* next;
};

void init_hashmap(struct node* hashmap[]){
    for(int i = 0 ; i < MAX ; i++){
        hashmap[i] = NULL;
    }
}

int hash(int key){
    return (key % MAX);
}

void insert(int key , struct node* hashmap[]){
    int index = hash(key);
    if(hashmap[index] == NULL){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = key;
        newnode->next  =NULL;
        hashmap[index] = newnode;
    }
    else{
        struct node* temp = hashmap[index];
        int flag = 0;
        while(temp->next != NULL){
            if(temp->data == key){
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if(flag == 0){
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = key;
            newnode->next  =NULL;
            hashmap[index] = newnode;
            temp->next = newnode;
        }
    }
}

int count(struct node* head){
    int cnt = 0;
    struct node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int valid(int *arr,int start,int end,int k){
    struct node* hashmap[MAX];
    init_hashmap(hashmap);
    for(int i = start ; i <= end ; i++){
        insert(arr[i],hashmap);
    }
    int cnt = 0;
    for(int i = 0 ; i< MAX ; i++){
        if(hashmap[i] != NULL){
            cnt += count(hashmap[i]);
        }
    }
    return cnt;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i; j  < n ; j++){
            if(valid(arr,i,j,k) == k){
                cnt++;
                printf("[");
                for(int k = i ; k < j ; k++){
                    printf("%d,",arr[k]);
                    
                }
                printf("]");
                printf("\n");
            }
        }
    }
    printf("%d",cnt);
}
