/*Sort an array using insertion sort.
Stable sort. Good for nearly sorted arrays.*/

#include <stdio.h>

void insertionSort(int arr[], int n) {
    size_t i = 1;

    while (i < (size_t)n) {
        int key = arr[i];
        size_t j = i;

        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = key;
        i++;
    }
}

int main() {
    int arr[] = {4, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    size_t k = 0;
    while (k < (size_t)n) {
        printf("%d ", arr[k]);
        k++;
    }

    return 0;
}
