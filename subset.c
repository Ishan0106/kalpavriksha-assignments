#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printsubsets(int arr[], int subset[], int n, int index, int subsetsize)
{
    printf("[");
    for (int i = 0; i < subsetsize; i++)
    {
        if (i > 0)
            printf(", ");
        printf("%d", subset[i]);
    }
    printf("]");

    for (int i = index; i < n; i++)
    {
        subset[subsetsize] = arr[i];
        printf(", ");
        printsubsets(arr, subset, n, i + 1, subsetsize + 1);
    }
}

int main()
{
    char input[30];
    fgets(input, sizeof(input), stdin);
    int arr[15];
    int index = 0;
    int n = strlen(input);

    for (int i = 0; i < n; i++)
    {
        while (input[i] == ' ')
            i++;
        if (input[i] == ',')
            i++;
        if (input[i] >= '0' && input[i] <= '9')
        {
            int num = 0;
            while (input[i] >= '0' && input[i] <= '9')
            {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            arr[index++] = num;
        }
    }

    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int subset[15];
    printf("[");
    printsubsets(arr, subset, index, 0, 0);
    printf("]\n");

    return 0;
}
