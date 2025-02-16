#include <stdio.h>
#include <string.h>

void swap(char input[], int l, int r)
{
    char temp = input[l];
    input[l] = input[r];
    input[r] = temp;
}

void helper(char input[], int l, int r)
{
    if (l == r)
    {
        printf("%s\n", input);
    }
    for (int i = l; i <= r; i++)
    {
        swap(input, l, i);
        helper(input, l + 1, r);
        swap(input, l, i);
    }
}

int main()
{
    char input[100];
    scanf("%s", input);
    int len = strlen(input);
    printf("permutations are below\n");
    helper(input, 0, len - 1);
    return 0;
}
