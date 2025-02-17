// hashmap frequency of given numbers
// linear probing
// array of structure
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct pair{
    int key;
    int value;
};

void init_hashmap(struct pair hashmap[]){
    for(int i = 0 ; i < MAX ; i++){
        hashmap[i].key = -1;
        hashmap[i].value = 0;
    }
}

int hash(int key){
    return key % 100;
}

void insert(int key , struct pair hashmap[]){
    int index = hash(key);
    while(hashmap[index].key!=-1 && hashmap[index].key!=key){
        index = (index + 1)%MAX;
    }
    if(hashmap[index].key==key)
    {
        hashmap[index].value++;
        return;
    }
    hashmap[index].key=key;
    hashmap[index].value++;
}


int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    struct pair hashmap[MAX];
    init_hashmap(hashmap);
    for(int i = 0 ; i < n ; i++){
        insert(arr[i],hashmap);
    }
    for(int i = 0 ; i < MAX ; i++){
        if(hashmap[i].key != -1){
            printf("%d -> %d\n",hashmap[i].key,hashmap[i].value);
        }
    }
    return 0;

}