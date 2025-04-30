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

void enqueue(struct queue* q, int val){
    if(q->rear == MAX - 1){
        printf("Queue is full\n");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = val;
}

int dequeue(struct queue* q){
    if(q->front == -1){
        return -1;  // Empty queue
    }
    int t = q->arr[q->front];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;  // Reset queue
    }
    else{
        q->front++;
    }
    return t;
}

void push(struct queue* q, int val){
    int n = q->rear - q->front + 1;
    enqueue(q, val);  // Corrected to pass address of queue
    while(n > 0){
        int t = dequeue(q);  // Corrected to pass address of queue
        enqueue(q, t);
        n--;
    }
}

void pop(struct queue* q){
    dequeue(q);  // Calling dequeue to remove an element
}

void display(struct queue* q){
    if(q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for(int i = q->front; i <= q->rear; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n--------------\n");
}

int main(){
    struct queue q;
    init(&q);
    
    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    push(&q, 40);
    push(&q, 50);
    
    display(&q);
    
    pop(&q);  // Remove element from front
    display(&q);
    
    pop(&q);  // Remove element from front
    display(&q);

    return 0;
}
