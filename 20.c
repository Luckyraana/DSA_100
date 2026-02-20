#include <stdio.h>

int main() {
    int n;
    int i, j;
    int count = 0;
    
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        int sum = 0;
        for (j = i; j < n; j++) {
            sum = sum + arr[j];

            if (sum == 0) {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
