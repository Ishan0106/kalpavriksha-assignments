#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct queue{
    int arr[MAX];
    int front;
    int rear;
};

void init(struct queue* q){
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct queue* q,int val){
    if(q->rear == MAX-1){
        return;
    }
    if(q->front == -1){
        q->front++;
    }
    q->rear++;
    q->arr[q->rear] = val;
}

void dequeue(struct queue* q){
    if(q->front == -1){
        return;
    }
    if(q->front == q->rear){
        q->front = -1;
        q->front = -1;
    }
    else{
        q->front++;
    }
}

int main(){
    struct queue q;
    init(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    int t = q.front;
    while(t <= q.rear){
        printf("%d ",q.arr[t++]);
    }
    printf("\n--------\n");
    dequeue(&q);
    t = q.front;
    while(t <= q.rear){
        printf("%d ",q.arr[t++]);
    }
    printf("\n--------\n");
    dequeue(&q);
    t = q.front;
    while(t <= q.rear){
        printf("%d ",q.arr[t++]);
    }
    printf("\n--------\n");
}