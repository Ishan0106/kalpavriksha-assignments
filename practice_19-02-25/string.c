#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    // char *s;
    // scanf("%[^\n]",s);
    // printf("%s",s);
    // char s1[100];
    // int n;
    // scanf("%d",&n);
    // getchar();
    // scanf("%[^\n]",s1);
    // printf("%s",s1);
    // printf("%d",n);
    int n;
    char s[100];
    fgets(s,sizeof(s),stdin);
    s[strcspn(s, "\n")] = '\0';
    scanf("%d",&n);
    printf("%s\n",s);
    printf("%d",n);
}