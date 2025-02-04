#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int start, int mid, int end) {
    int t = start; 
    int n = end - start + 1; 
    int temp[n]; 
    int index = 0; 
    int st = mid + 1; 
    while (start <= mid && st <= end) {
        if (arr[start] < arr[st]) {
            temp[index++] = arr[start++];
        } else {
            temp[index++] = arr[st++];
        }
    }
    while (start <= mid) {
        temp[index++] = arr[start++];
    }
    while (st <= end) {
        temp[index++] = arr[st++];
    }
    for (int i = 0; i < n; i++) {
        arr[t + i] = temp[i]; 
    }
}

void mergesort(int arr[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2; 
        mergesort(arr, start, mid);   
        mergesort(arr, mid + 1, end); 
        merge(arr, start, mid, end);  
    }
}

int main() {
    int n, i;
    scanf("%d", &n); 
    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
