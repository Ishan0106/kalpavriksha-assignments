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
    if(s->top == MAX){
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

int main(){
    struct stack s;
    init(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    int t = s.top;
    while(t >= 0){
        printf("%d ",s.arr[t]);
        t--;
    }
    printf("----------\n");
    int temp = pop(&s);
    printf("%d\n",temp);
    int tep2 = peek(&s);
    printf("%d\n",tep2);
}