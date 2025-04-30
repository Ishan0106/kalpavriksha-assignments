#include <stdio.h>
#include <string.h>

int check(char input[], int i, int j)
{
    while (i < j)
    {
        if (input[i] != input[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main()
{
    char input[1000];
    // char result[1000];
    int i, j, start, end, maxi;
    maxi = 0;
    scanf("%s", input);
    int len = strlen(input);
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (check(input, i, j) == 1)
            {
                int t = j - i + 1;
                if (t > maxi)
                {
                    maxi = t;
                    start = i;
                    end = j;
                }
            }
        }
    }
    for (i = start; i <= end; i++)
    {
        printf("%c", input[i]);
    }
    return 0;
}
