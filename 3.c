#include <stdio.h>

int main() {
    int n, k,i;
    int comparisons = 0;
    int foundIndex = -1;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key
    scanf("%d", &k);

    // Linear search
    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            foundIndex = i;
            break;
        }
    }

    // Output result
    if (foundIndex != -1) {
        printf("Found at index %d\n", foundIndex);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", comparisons);

    return 0;
}

