/*You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces*/

#include <stdio.h>

int main() {
    int r, c;
    int i, j; 
    scanf("%d %d", &r, &c);

    int matrix[10][10];

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right) {
        for (j = left; j <= right; j++)
            printf("%d ", matrix[top][j]);
        top++;

        for (i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        if (top <= bottom) {
            for (j = right; j >= left; j--)
                printf("%d ", matrix[bottom][j]);
            bottom--;
        }

        if (left <= right) {
            for (i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }

    return 0;
}
