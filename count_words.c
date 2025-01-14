#include <stdio.h>
#include <string.h>
int main()
{
    char arr[100];
    fgets(arr, sizeof(arr), stdin);
    int i, j, count = 0;
    for (i = 0; arr[i] != '\0'; i++)
        ;
    for (j = 0; j < i; j++)
    {
        if (j == 0 && arr[j] != ' ')
        {
            count++;
        }
        else if (arr[j] != ' ' && arr[j - 1] == ' ')
        {
            count++;
        }
    }
    printf("count is %d :", count);
    return 0;
}