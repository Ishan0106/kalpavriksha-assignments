#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,j;
    char st[100];
    printf("enter the value for N\n");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    for(j = 0 ; j < n ; j++){
        printf("%d ",arr[j]);
    }
    getchar();
    scanf("%[^'\n']s",st);
    printf("%s",st);
}
