#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char s1[100];
    char s2[100];
    char s3[100];
    scanf("%s",s1);
    scanf("%s",s2);
    scanf("%s",s3);
    printf("%s\n",s1);
    printf("%s\n",s2);
    strcat(s1,s2);
    printf("%s\n",s1);
    if(strcmp(s1,s3) == 0){
        printf("true\n");
    }
}