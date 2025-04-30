#include<stdio.h>
#include<stdlib.h>

struct stack{
    char arr[100];
    int top;
};

void push(struct stack *st,char opr){
    st->top++;
    st->arr[st->top] = opr;
    return;
}

char pop(struct stack* st){
    char poped = st->arr[st->top];
    st->top--;
    return poped;
}

int main(){
    char str[100];
    char result[100];
    int index = 0;
    int flag = 0;
    scanf("%s",str);
    struct stack st;
    st.top = -1;
    for(int i = 0 ; str[i] != '\0' ; i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '^'){
            push(&st,str[i]);
        }
        else{
            if(st.top == -1){ 
                flag = 1;
                break;
            }
            result[index++] = str[i];
            char temp = pop(&st);
            result[index++] = temp;
        }
    }
    if(flag == 1){
        printf("invalid expresion\n");
    }
    else{
        result[index] = '\0';
        printf("%s",result);
    }
    return 0;
}
