#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void helper(int arr[], int index, int n, int k, int start)
{
    if (index == k)
    {
        for (int i = 0; i < k; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i <= n; i++)
    {
        arr[index] = i;
        helper(arr, index + 1, n, k, i + 1);
    }
}

int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    int arr[k];
    helper(arr, 0, n, k, 1);
    return 0;
}
