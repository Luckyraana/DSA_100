/*Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the first matrix
- Next m lines: n integers each representing the elements of the second matrix

Output:
- Print the resultant matrix after addition, with each row on a new line and elements separated by spaces*/

#include <stdio.h>

#define MAX 100

int main() {
    int m, n;
    int A[MAX][MAX], B[MAX][MAX], sum[MAX][MAX];
    int i, j;  

    scanf("%d %d", &m, &n);

   
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

   
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

   
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}

