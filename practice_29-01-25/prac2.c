//push operation in stack using array

#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;

void push(int data){
    if(top == MAX-1){
        printf("stack overflow");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    printf("stack elemnets are\n");
    int ptr = top;
    while(ptr >= 0){
        printf("%d ",stack_arr[ptr]);
        ptr--;
    }
    return 0;
}
