#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, r, c;
    printf("enter the number of rows:\n");
    scanf("%d", &r);
    printf("enter the number of columns:\n");
    scanf("%d", &c);
    int matrix[r][c];
    printf("enter the elements of the matrix\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("diagonal elements of the matrix are : ");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (i == j)
            {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    printf("\n");
    return 0;
}
