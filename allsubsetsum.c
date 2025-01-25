#include <stdio.h>

void subsetSum(int arr[], int l, int r, int sum)
{
    if (l > r)
    {
        printf("%d ", sum);
        return;
    }

    subsetSum(arr, l + 1, r, sum + arr[l]);

    subsetSum(arr, l + 1, r, sum);
}

int main()
{
    int arr[] = {4, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    subsetSum(arr, 0, n - 1, 0);
    return 0;
}

// second way
// using bit manipulation
/*
#include <stdio.h>

void subsetSums(int arr[], int n)
{
    // There are total 2^n subsets
    long long total = 1 << n;

    // Consider all numbers from 0 to 2^n - 1
    for (long long i = 0; i < total; i++) {
        long long sum = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                sum += arr[j];

        // Print sum of picked elements.
        printf("%lld ", sum);
    }
}

int main()
{
    int arr[] = { 4, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    subsetSums(arr, n);
    return 0;
}

*/