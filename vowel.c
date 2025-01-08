#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 10
#define MAX_COLS 101
#define MAX_NAME_LEN 50

int is_vowel(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    int rows, cols;
    char names[MAX_ROWS][MAX_COLS][MAX_NAME_LEN + 1];
    int valid_input = 1;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    if (rows < 1 || rows > MAX_ROWS)
    {
        printf("Error: Rows should be between 1 and 10.\n");
        valid_input = 0;
    }

    printf("Enter number of columns: ");
    scanf("%d", &cols);
    if (cols < 1 || cols > MAX_COLS)
    {
        printf("Error: Columns should be between 1 and 101.\n");
        valid_input = 0;
    }

    if (valid_input)
    {
        printf("Enter the names:\n");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("Name at (%d,%d): ", i, j);
                scanf("%s", names[i][j]);
            }
        }

        printf("\nThe 2D array of names is:\n");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("%s ", names[i][j]);
            }
            printf("\n");
        }

        int vowel_count = 0;
        char longest_name[MAX_NAME_LEN + 1] = "";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (is_vowel(names[i][j][0]))
                {
                    vowel_count++;
                }
                if (strlen(names[i][j]) > strlen(longest_name))
                {
                    strcpy(longest_name, names[i][j]);
                }
            }
        }

        printf("\nNumber of names starting with a vowel: %d\n", vowel_count);
        printf("The longest name: %s\n", longest_name);
    }

    return 0; // Single exit point
}
