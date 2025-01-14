#include <stdio.h>
#include <string.h>

int main()
{
    char arr[100], ans[100];
    int i, j, index = 0;
    int found;
    fgets(arr, sizeof(arr), stdin);
    int len = strlen(arr);
    for (i = 0; i < len; i++)
    {
        found = 0;
        for (j = 0; j < index; j++)
        {
            if (ans[j] == arr[i])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            ans[index++] = arr[i];
        }
    }
    ans[index] = '\0';
    printf("%s\n", ans);
    return 0;
}
