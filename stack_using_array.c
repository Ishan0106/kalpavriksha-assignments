#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

typedef struct{
    int arr[MAX_SIZE];
    int top;
}stack;

void push(stack *st,int val){
    if(st->top == MAX_SIZE-1){
        printf("Stack overflow\n");
        return;
    }
    st->top++;
    st->arr[st->top] = val;
}

void pop(stack *st){
    if(st->top == -1){
        printf("srack underflow\n");
        return;
    }
    st->top--;
}

void peek(stack *st){
    if(st->top == -1){
        printf("Stack has no elements\n");
        return;
    }
    printf("%d",st->arr[st->top]);
}

void isEmpty(stack *st){
    if(st->top == -1){
        printf("yes Stack is empty\n");
        return;
    }
    printf("No stack is not empty\n");
}

void size(stack *st){
    if(st->top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("%d",st->top+1);
}

void print(stack *st){
    int t = st->top;
    while(t--){
        printf("%d\n",st->arr[t]);
    }
    return;
}

int main(){
    stack st;
    st.top = -1;
    int choice;
    do{
        printf("stack operations\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.isEmpty\n");
        printf("5.size\n");
        printf("6.printStack\n");
        printf("7.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        if(choice == 1){
            int value;
            printf("enter the value\n");
            scanf("%d",&value);
            push(&st,value);
        }
        else if(choice == 2){
            pop(&st);
        }
        else if(choice == 3){
            peek(&st);
        }
        else if(choice == 4){
            isEmpty(&st);
        }
        else if(choice == 5){
            size(&st);
        }
        else if(choice == 6){
            print(&st);
        }
        else if(choice == 7){
            break;
        }
    }while(choice != 6);
    return 0;
}