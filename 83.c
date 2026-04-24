/*Implement Selection Sort - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

*/

#include <stdio.h>

int main() {
    int n, i, j, min, temp;

    scanf("%d", &n);

    int a[n];

    i = 0;
    while (i < n) {
        scanf("%d", &a[i]);
        i++;
    }

    i = 0;
    while (i < n - 1) {
        min = i;
        j = i + 1;

        while (j < n) {
            if (a[j] < a[min]) {
                min = j;
            }
            j++;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        i++;
    }

    i = 0;
    while (i < n) {
        printf("%d ", a[i]);
        i++;
    }

    return 0;
}
