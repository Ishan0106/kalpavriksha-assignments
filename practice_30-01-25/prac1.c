
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *arr = (int *)malloc(1*sizeof(int));
    arr[0] = 1;
    int *next = arr;
    int size = 5;
    while(1){
        int val;
        scanf("%d",&val);
        next = next + 1;
        *next = val;
        if(val==999)
        {break;
            
        }
    }
    printf("%p\n",arr);
    for(int *ptr = arr ; ptr != next ; ptr++){
        printf("%d ",*ptr);
    }
}


