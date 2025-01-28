#include <stdio.h>
#include <stdlib.h>

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort Helper Function
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort Partition Function
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Linear Search
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Two-Pointer Technique
int twoPointerSearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
            return 1;
        else if (sum < target)
            left++;
        else
            right--;
    }
    return 0;
}

// Utility Function to Print Array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: \n");
    printArray(arr, n);

    // Bubble Sort
    int bubbleArr[] = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(bubbleArr, n);
    printf("Bubble Sorted Array: \n");
    printArray(bubbleArr, n);

    // Selection Sort
    int selectionArr[] = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(selectionArr, n);
    printf("Selection Sorted Array: \n");
    printArray(selectionArr, n);

    // Insertion Sort
    int insertionArr[] = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(insertionArr, n);
    printf("Insertion Sorted Array: \n");
    printArray(insertionArr, n);

    // Merge Sort
    int mergeArr[] = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(mergeArr, 0, n - 1);
    printf("Merge Sorted Array: \n");
    printArray(mergeArr, n);

    // Quick Sort
    int quickArr[] = {64, 34, 25, 12, 22, 11, 90};
    quickSort(quickArr, 0, n - 1);
    printf("Quick Sorted Array: \n");
    printArray(quickArr, n);

    // Linear Search
    int key = 25;
    int linearIndex = linearSearch(arr, n, key);
    printf("Linear Search: Element %d found at index %d\n", key, linearIndex);

    // Binary Search
    int binaryIndex = binarySearch(mergeArr, 0, n - 1, key);
    printf("Binary Search: Element %d found at index %d\n", key, binaryIndex);

    // Two-Pointer Technique
    int target = 37;
    int twoPointerResult = twoPointerSearch(mergeArr, n, target);
    printf("Two-Pointer Technique: Pair with sum %d %s\n", target, twoPointerResult ? "exists" : "does not exist");

    return 0;
}
