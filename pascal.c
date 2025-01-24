#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);
    n--;
    int *arr = (int *)malloc((n + 1) * sizeof(int));
    arr[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            arr[j] = (j == i) ? 1 : arr[j] + arr[j - 1];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (i > 0)
            printf(",");
        printf("%d", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}