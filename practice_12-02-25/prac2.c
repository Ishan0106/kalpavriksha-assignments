#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *s_id;
    float *temp;
    unsigned long *time;
}node;


void addreading(int index,node* arr,int k,int t){
    *(arr[index].s_id) = k;
    *(arr[index].time) = t;
    *(arr[index].temp) = 125 - rand()%165;
}

void print_reading(node* arr,int n){
    int i;
    for(i = 0 ; i < n ; i++){
        printf("Sensor ID: %d, Temp: %0.2fC, Timestamp: %ld\n",*(arr[i].s_id) ,*(arr[i].temp),*(arr[i].time));
    }
    return;
}

void free_memory(node* arr,int n){
    int i;
    for(i = 0 ; i< n ; i++){
        free(arr[i].s_id);
        free(arr[i].temp);
        free(arr[i].time);
    }
    free(arr);
}


int main(){
    int n;
    printf("enter the value of n\n");
    scanf("%d",&n);
    node* arr = malloc(n*sizeof(node));
    int index = 0;
    int timestamp = 17000000;
    for(int i = 0; i < n ; i++){
        arr[index].s_id=malloc(sizeof(int));
        arr[index].time=malloc(sizeof(unsigned long));
        arr[index].temp=malloc(sizeof(float));
        int k;
        printf("enter sensor id\n");
        scanf("%d",&k);
        addreading(index,arr,k,timestamp);
        timestamp++;
        index++;
    }
    print_reading(arr,n);
    free_memory(arr,n);
}