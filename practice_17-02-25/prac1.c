#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int is_distinct(char str[],int i,int j){
    int arr[26] = {0};
    int cnt = 0;
    for(int p = i ; p <= j ; p++){
        arr[str[p] - 'a'] = 1;
    }
    for(int p = 0 ; p <= 25 ; p++){
        if(arr[p] == 1){
            cnt++;
        }
    }
    return cnt;
}


int main(){
    char str[100];
    int k;
    scanf("%s",str);
    scanf("%d",&k);
    int n = strlen(str);
    int max_len = 0;
    int start = -1;
    int end = -1;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(is_distinct(str,i,j) == k){
                if(j-i+1 > max_len){
                    max_len=j-i+1;
                    start = i;
                    end = j;
                }
            }
        }
    }
    if(start == -1){
        printf("%d",-1);
        return 0;
    }
    for(int i=start;i<=end;i++)
    {
        printf("%c",str[i]);
    }
    return 0;
}
