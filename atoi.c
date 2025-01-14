#include <stdio.h>

int main()
{
    char input[100];
    scanf("%s", input);
    int sign = 1, num = 0, invalid = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '-')
        {
            sign = -1;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            num = num * 10 + (input[i] - '0');
        }
        else
        {
            invalid = 1;
            break;
        }
    }
    if (invalid == 1)
    {
        printf("your input is invalid\n");
    }
    else
    {
        if (sign == -1)
            num = sign * num;
        printf("digit converted is : %d\n", num);
    }
    return 0;
}