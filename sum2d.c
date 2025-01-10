#include <stdio.h>
int main()
{
    int r, c, i, j, sum = 0, prod = 1;
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
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            sum += matrix[i][j];
            prod *= matrix[i][j];
        }
    }
    printf("sum of the elements of the matrix is = %d\n", sum);
    printf("product of the elements of the matrix is = %d\n", prod);
    return 0;
}