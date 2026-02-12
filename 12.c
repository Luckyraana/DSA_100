/*Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the matrix

Output:
- Print "Symmetric Matrix" if the given matrix is symmetric
- Otherwise, print "Not a Symmetric Matrix"*/

#include <stdio.h>

int main()
{
    int m, n;
    int i, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[100][100];

    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }


    if(m != n)
    {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(matrix[i][j] != matrix[j][i])
            {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix");

    return 0;
}

