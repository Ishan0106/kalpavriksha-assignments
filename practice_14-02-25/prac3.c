#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
#define MAX_NUM 10000

typedef struct{
    int val;
    int index;
    struct node* next;
}node;

node* hashmap[MAX] = {NULL};

int hash(int key){
    return abs(key%MAX);
}

void insert(int data,int ind){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->val = data;
    newnode->index = ind;
    newnode->next = NULL;
    int pos = hash(data);
    if(hashmap[pos] == NULL){
        hashmap[pos] = newnode;
    }
    else{
        node* temp = hashmap[pos];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

int find(int data){
    int pos = hash(data);
    if(hashmap[pos] == NULL){
        return -1;
    }
    node* temp = hashmap[pos];
    while(temp != NULL){
        if(temp->val == data){
            return temp->index;
        }
        temp = temp->next;
    }
    return -1;
}

int main(){
    int n,first,target,req;
    printf("enter number of elements\n");
    scanf("%d",&n);
    printf("enter the target value\n");
    scanf("%d",&target);
    int nums[MAX_NUM];
    printf("enter the array values\n");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&nums[i]);
    }
    for(int i = 0 ; i < n ; i++){
        first = nums[i];
        req = target - first;
        int ans = find(req);
        if(ans == -1){
            insert(first,i);
        }
        else{
            printf("[%d, %d]",ans,i);
            return 1;
        }
    }
    return 0;
}

