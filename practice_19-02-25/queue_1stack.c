#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct stack{
    int arr[100];
    int top;
};

void init(struct stack* s){
    s->top = -1;
}

void push(struct stack* s,int val){
    if(s->top == MAX-1){
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}

int pop(struct stack* s){
    if(s->top == -1){
        return -1;
    }    
    return s->arr[s->top--];
}

int peek(struct stack* s){
    if(s->top == -1){
        return -1;
    }  
    return s->arr[s->top];
}

void enqueue(struct stack* s,int val){
    if(s->top == -1){
        push(s,val);
        return;
    }
    int t = pop(s);
    enqueue(s,val);
    push(s,t);
}

void dequeue(struct stack* s){
    pop(s);
}

void display(struct stack* s){
    int n = s->top;
    while(n >= 0){
        printf("%d ",s->arr[n]);
        n--;
    }
    printf("\n--------------\n");
}

int main(){
    struct stack s;
    init(&s);
    enqueue(&s,10);
    enqueue(&s,20);
    enqueue(&s,30);
    enqueue(&s,40);
    enqueue(&s,50);
    display(&s);
    dequeue(&s);
    display(&s);
}