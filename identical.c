#include <stdio.h>
#define SIZE 3

int areIdentical(int Matrix1[][SIZE], int Matrix2[][SIZE])
{
    int i = 0;
    int j = 0;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (Matrix1[i][j] != Matrix2[i][j])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int Matrix1[SIZE][SIZE] = {
        {1, 2, 9},
        {2, 1, 3},
        {3, 2, 1},
    };

    int Matrix2[SIZE][SIZE] = {
        {1, 2, 3},
        {2, 1, 3},
        {3, 2, 1},
    };

    if (areIdentical(Matrix1, Matrix2))
        printf("Both matrices are identical\n");
    else
        printf("Matrices are not identical\n");

    return 0;
}
