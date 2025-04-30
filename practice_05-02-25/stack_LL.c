#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    struct node* next;
}node;

typedef struct{
    node* top;
}stack;

void push(stack *s,int val){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    if(s->top == NULL){
        s->top = temp;
    }
    else{
        temp->next = s->top;
        s->top = temp;
    }
}

void pop(stack *s){
    node* t = s->top;
    s->top = s->top->next;
    free(t);
}

void display(stack *s){
    node* temp = s->top;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int ch;
    stack s;
    s.top = NULL;
    do{
        printf("stack operations\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        getchar();
        if(ch == 1){
            int value;
            scanf("%d",&value);
            push(&s,value);
        }
        else if(ch == 2){
            pop(&s);
        }
        else if(ch == 3){
            printf("%d",s.top->data);
        }
        else if(ch == 4){
            display(&s);
        }
    }while(ch != 5);
    return 5;
}


