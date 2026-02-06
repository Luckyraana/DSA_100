#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n); 

    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
    }

    if (n == 0) return 0; 

    int lastUnique = 0; 

    for (i = 1; i < n; i++) {
        if (arr[i] != arr[lastUnique]) {
            lastUnique++;
            arr[lastUnique] = arr[i]; 
        }
    }

    
    for (i = 0; i <= lastUnique; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

