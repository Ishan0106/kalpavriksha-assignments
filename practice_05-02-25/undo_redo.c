#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
    char arr[MAX];
    int top;
}stack;

void display(stack *s){
    if (s->top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    int i;
    for(i = 0; i <= s->top; i++){
        printf("%c", s->arr[i]);
    }
    printf("\n");
}

int main(){
    int choice;
    stack undo;
    stack redo;
    undo.top = -1;
    redo.top = -1;

    do{
        printf("1. Type\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        if(choice == 1){
            if (undo.top == MAX - 1) {
                printf("Undo stack overflow. Cannot type more.\n");
            } else {
                char ch;
                printf("Enter character: ");
                scanf("%c", &ch);
                undo.top++;
                undo.arr[undo.top] = ch;
                display(&undo);
            }
        }
        else if(choice == 2){
            if (undo.top == -1) {
                printf("Undo stack is empty. No action to undo.\n");
            } else {
                char ch = undo.arr[undo.top];
                undo.top--;
                if (redo.top == MAX - 1) {
                    printf("Redo stack overflow. Cannot redo more.\n");
                } else {
                    redo.top++;
                    redo.arr[redo.top] = ch;
                }
                display(&undo);
            }
        }
        else if(choice == 3){
            if (redo.top == -1) {
                printf("Redo stack is empty. No action to redo.\n");
            } else {
                char ch = redo.arr[redo.top];
                redo.top--;
                if (undo.top == MAX - 1) {
                    printf("Undo stack overflow. Cannot undo more.\n");
                } else {
                    undo.top++;
                    undo.arr[undo.top] = ch;
                }
                display(&undo);
            }
        }
        else if(choice == 4) {
            printf("Exiting program.\n");
        }
        else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while(choice != 4);

    return 0;
}
