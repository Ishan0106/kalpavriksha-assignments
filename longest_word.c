#include <stdio.h>
#include <string.h>

void longest_word(char sentence[])
{
    int maxLength = 0;
    int currentLength = 0;
    int start = 0, end = 0, wordStart = 0;

    for (int i = 0; i <= strlen(sentence); i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\0')
        {
            if (currentLength > maxLength)
            {
                maxLength = currentLength;
                start = wordStart;
                end = i - 1;
            }
            currentLength = 0;
            wordStart = i + 1;
        }
        else
        {
            currentLength++;
        }
    }

    for (int i = start; i <= end; i++)
    {
        putchar(sentence[i]);
    }
    printf("\n");
}

int main()
{
    char sentence1[1000];
    fgets(sentence1, sizeof(sentence1), stdin);
    sentence1[strcspn(sentence1, "\n")] = '\0';
    longest_word(sentence1);
    return 0;
}
