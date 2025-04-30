#include<stdio.h>
#include<stdlib.h>

void sort(int *arr,int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    
    sort(arr, n);
    
    int start = 0;
    int temp1 = 0;
    int temp2 = 0;
    int end = 0;
    int maxi = 1;
    
    // Loop through the array to find the longest consecutive subsequence
    for(int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1] + 1) {
            end = i;
            if(end - start + 1 > maxi){
                temp1 = start;
                temp2 = end;
                maxi = end - start + 1;
            }
        } else {
            start = i;
            end = i;
        }
    }
    printf("[");
    for(int i = temp1; i <= temp2; i++) {
        printf("%d", arr[i]);
        if (i < end) {  // Avoid printing an extra comma after the last element
            printf(", ");
        }
    }
    printf("]\n");
    
    free(arr);  // Free the allocated memory
    return 0;
}
