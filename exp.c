#include <stdio.h>

long helper(long a, long b, long c)
{
    long result = 1;
    a = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % c;
        }
        b = b / 2;
        a = (a * a) % c;
    }
    return result;
}

int main()
{
    long a, b, c;
    printf("Enter values for a, b, and c: ");
    scanf("%ld %ld %ld", &a, &b, &c);
    long result = helper(a, b, c);
    printf("Result: %ld\n", result);
    return 0;
}
