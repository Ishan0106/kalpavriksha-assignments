#include <stdio.h>
#include <string.h>

// Function to find the starting index of a substring in a string
int findSubstring(char string[], char substring[])
{
    int len1 = strlen(string);
    int len2 = strlen(substring);

    // Loop through each starting position in the main string
    for (int i = 0; i <= len1 - len2; i++)
    {
        int j;

        // Check if substring matches character by character
        for (j = 0; j < len2; j++)
        {
            if (string[i + j] != substring[j])
            {
                break;
            }
        }

        // If the substring matches completely
        if (j == len2)
        {
            return i; // Starting index
        }
    }

    // If substring is not found
    return -1;
}

int main()
{
    char string[100], substring[100];

    printf("Enter the main string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0'; // Remove newline

    printf("Enter the substring: ");
    fgets(substring, sizeof(substring), stdin);
    substring[strcspn(substring, "\n")] = '\0'; // Remove newline

    int result = findSubstring(string, substring);
    printf("Output: %d\n", result);

    return 0;
}
