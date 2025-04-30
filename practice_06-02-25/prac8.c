#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int low,int mid,int high){
    int size = high - low + 1;
    int temp[size];
    int index = 0;
    int start1 = low;
    int start2 = mid+1;
    while(start1 <= mid && start2 <= high){
        if(arr[start1] < arr[start2]){
            temp[index++] = arr[start1++];
        }
        else{
            temp[index++] = arr[start2++];
        }
    }
    while(start1 <= mid){
        temp[index++] = arr[start1++];
    }

    while(start2 <= high){
        temp[index++] = arr[start2++];
    }

    for(int i = 0 ; i < index ; i++){
        arr[i+low] = temp[i];
    }
}


void mergesort(int arr[],int low,int high){
    if(low < high){
        int mid = (low + high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    int arr[8] = {4,2,7,3,9,1,3,6};
    mergesort(arr,0,7);
    for(int j  = 0 ; j < 8 ; j++){
        printf("%d ",arr[j]);
    }
}