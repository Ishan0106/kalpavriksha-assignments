#include <stdio.h>

void concat(char *s1, char *s2)
{
    while (*s1)
        s1++;

    while (*s2)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

int main()
{
    char s1[100] = "Hello, ";
    char s2[] = "World!";

    concat(s1, s2);

    printf("%s\n", s1);
    return 0;
}