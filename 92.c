 /*Implement Quick Sort using partition method (Lomuto or Hoare).*/
 
 #include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Lomuto Partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    size_t j;   // no int in loop

    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};

    size_t n = sizeof(arr) / sizeof(arr[0]);  // no int

    quickSort(arr, 0, n - 1);

    size_t i;   // no int in loop
    printf("Sorted array: ");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
