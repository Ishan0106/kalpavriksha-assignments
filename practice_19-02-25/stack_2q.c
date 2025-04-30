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

void push(struct queue* q1, struct queue* q2, int val){

    int n = q1->rear - q1->front + 1;
    // Push to stack using two queues
    enqueue(q1, val);  // Add the new element to q1
    
    // Move all elements from q1 to q2 to reverse the order
    
    while(n > 0){
        int t = dequeue(q1);
        enqueue(q2, t);
        n--;
    }
    
    // Now move elements back from q2 to q1, with the new element at the front of q1
    n = q2->rear - q2->front + 1;
    while(n > 0){
        int t = dequeue(q2);
        enqueue(q1, t);
        n--;
    }
}

void pop(struct queue* q1){
    dequeue(q1);  // Pop the top element from the stack (front of q1)
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
    struct queue q1, q2;
    init(&q1);
    init(&q2);
    
    // Using q1 and q2 to simulate stack operations
    push(&q1, &q2, 10);
    push(&q1, &q2, 20);
    push(&q1, &q2, 30);
    push(&q1, &q2, 40);
    
    display(&q1);  // Display stack
    
    pop(&q1);      // Pop one element
    display(&q1);  // Display stack after pop
    
    pop(&q1);      // Pop another element
    display(&q1);  // Display stack after pop

    return 0;
}
