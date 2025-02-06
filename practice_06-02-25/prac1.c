// stack using array

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
    int arr[MAX];
    int top;
}stack;

void init(stack* s){
    s->top = -1;
}

void push(stack* s,int val){
    s->top++;
    s->arr[s->top] = val;
}

void pop(stack* s){
    s->top--;
}

void peek(stack* s){
    printf("%d\n",s->arr[s->top]);
}

void display(stack* s){
    int temp = s->top;
    while(temp >= 0){
        printf("%d ",s->arr[temp]);
        temp--;
    }
    printf("\n");
}

int main(){
    stack s;
    init(&s);
    int choice;
    do{
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("enter choice\n");
        scanf("%d",&choice);
        if(choice == 1){
            int val;
            scanf("%d",&val);
            push(&s,val);
        }
        else if(choice == 2){
            pop(&s);
        }
        else if(choice == 3){
            peek(&s);
        }
        else if(choice == 4){
            display(&s);
        }
    }while(choice != 5);
}

