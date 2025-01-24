#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);

    int head = 1;
    int step = 1;
    int left = 1;

    while (n > 1)
    {
        if (left || n % 2 != 0)
        {
            head += step;
        }
        step *= 2;
        n /= 2;
        left = !left;
    }

    printf("%d\n", head);
    return 0;
}