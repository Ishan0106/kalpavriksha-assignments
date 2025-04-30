#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct{
    char arr[MAX][MAX];
    int top;
}stack;

void push(stack *s,char *str){
    if(s->top == MAX-1){
        printf("No space remain in stack\n");
        return;
    }
    s->top++;
    strcpy(s->arr[s->top],str);
}

void view_history(stack* s){
    if (s->top == -1) {
        printf("History is empty.\n");
        return;
    }
    int temp = s->top;
    while (temp >= 0) { 
        printf("%s\n", s->arr[temp]);
        temp--;
    }
}

void edit(stack* s,char *str,char* str1){
    int temp = s->top;
    while(temp >= 0){
        if(strcmp(s->arr[temp],str) == 0){
            strcpy(s->arr[temp],str1);
            break;
        }
        temp--;
    }
}

void delete(stack* s){
    if(s->top == -1){
        printf("nothing is there in stack\n");
        return;
    }
    s->top--;
}

void clear(stack *s){
    s->top = -1;
}

int main(){
    stack s;
    s.top = -1;
    int choice;
    do{
        printf("Browser history management system\n");
        printf("1.ADD A WEBSITE\n");
        printf("2.VIEW HISTORY\n");
        printf("3.EDIT A URL\n");
        printf("4.DELETE MOST RECENT WEBSITE\n");
        printf("5.MOST RECENT WEBSITE USED\n");
        printf("6.CLEAR HISTORY\n");
        printf("7.EXIT\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        getchar();
        if(choice == 1){
            char str[MAX];
            printf("enter a url\n");
            fgets(str,sizeof(str),stdin);
            str[strcspn(str, "\n")] = '\0';
            push(&s,str);
        }
        else if(choice == 2){
            view_history(&s);
        }
        else if(choice == 3){
            char str[MAX];
            char str1[MAX];
            printf("enter the url to edit\n");
            fgets(str,sizeof(str),stdin);
            str[strcspn(str, "\n")] = '\0';
            printf("enter the updated url\n");
            fgets(str1,sizeof(str1),stdin);
            str1[strcspn(str1, "\n")] = '\0';
            edit(&s,str,str1);
        }
        else if(choice == 4){
            delete(&s);   
        }
        else if(choice == 5){
            if(s.top == -1){
                printf("stack empty\n");
            }
            else{
                printf("%s",s.arr[s.top]);
            }
        }
        else if(choice == 6){
            clear(&s);
        }
    }while(choice != 7);
}