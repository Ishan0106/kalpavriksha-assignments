#include <stdio.h>
#include <string.h>

// Function to check if one string is a rotation of another
int isRotation(char string1[], char string2[])
{
    int len1 = strlen(string1);
    int len2 = strlen(string2);

    // Strings must be of the same length to be rotations
    if (len1 != len2)
    {
        return 0;
    }

    // Create a temporary string by concatenating string1 with itself
    char temp[2 * len1 + 1];
    strcpy(temp, string1);
    strcat(temp, string1);

    // Check if string2 is a substring of temp
    int lenTemp = strlen(temp);
    int lenSub = strlen(string2);

    for (int i = 0; i <= lenTemp - lenSub; i++)
    {
        int j;
        for (j = 0; j < lenSub; j++)
        {
            if (temp[i + j] != string2[j])
            {
                break;
            }
        }
        if (j == lenSub)
        {
            return 1; // string2 is found in temp
        }
    }

    return 0; // string2 is not found in temp
}

int main()
{
    char string1[100], string2[100];

    printf("Enter the first string: ");
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0'; // Remove newline

    printf("Enter the second string: ");
    fgets(string2, sizeof(string2), stdin);
    string2[strcspn(string2, "\n")] = '\0'; // Remove newline

    if (isRotation(string1, string2))
    {
        printf("Output: true\n");
    }
    else
    {
        printf("Output: false\n");
    }

    return 0;
}
