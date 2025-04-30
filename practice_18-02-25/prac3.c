#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct stack{
    int top;
    int arr[MAX];
}


init_stack(struct stack* s){
    s->top = -1;
}

void push(int val , struct stack* s){
    if(s->top == MAX){
        printf("stack full\n");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}

int pop(struct stack* s){
    if(s->top == -1){
        printf("stack empty\n");
        return -1;
    }
    int val=s->arr[s->top];
    s->top--;
    return val;
}

void enqueue(struct stack* s,int val)
 {
//     if(s->top==-1)
//     {
//         push(val,s);
//         return;
//     }
//     int temp=pop(s);
//     enqueue(s,val);
//     push(temp,s);
       push(val,s);
}

void dequeue(struct stack* s){
    if(s->top == -1){
        return ;
    }
    if(s->top == 0){
        pop(s);
        return;
    }
    int temp = pop(s);
    dequeue(s);
    push(temp,s);
}

int main(){
    struct stack s;
    init_stack(&s);
    enqueue(&s,10);
    enqueue(&s,20);
    enqueue(&s,30);
    enqueue(&s,40);
    enqueue(&s,50);
    dequeue(&s);
    for(int i=0;i<=s.top;i++)
        printf("%d ",s.arr[i]);
    // printf("%d",num);
}