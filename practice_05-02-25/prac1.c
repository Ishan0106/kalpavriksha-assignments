#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200

typedef struct{
    char string_arr[MAX][MAX];
    int top;
}str_stack;

typedef struct{
    int num_arr[MAX];
    int top;
}num_stack;

int main(){
    str_stack s1;
    num_stack s2;
    s1.top = -1;
    s2.top = -1;
    char input[MAX];
    scanf("%s",input);
    int n = strlen(input);
    int num = 0;
    for(int i = 0 ; i < n ;i++){
        if(input[i] >= '0' && input[i] <= '9'){
            num = num*10 + (input[i] - '0');
        }
        else if(input[i] == ']'){
            char temp[MAX] = " ";
            char cur[MAX] = " ";
            char ps[MAX] = " ";
            while(strcmp(s1.string_arr[s1.top],"[") != 0){
                strcat(temp,s1.string_arr[s1.top]);
                s1.top--;
            }
            int N = strlen(temp);
            int index = 0;
            for(int j = N-1 ; j >= 0 ; j--){
                cur[index++] = temp[j];
            }
            cur[index] = '\0';
            int times = s2.num_arr[s2.top--];
            for(int k = 0 ; k < times ; k++){
                strcat(ps,cur);
            }
            strcpy(s1.string_arr[s1.top],ps);
        }
        else if(input[i] == '['){
            s2.num_arr[++s2.top] = num;
            num = 0;
            strcpy(s1.string_arr[++s1.top],"[");
        }
        else{
            strcpy(s1.string_arr[++s1.top],input[i]);
        }
    }
    printf("%s\n",s1.string_arr[s1.top]);
    return 0;
}
