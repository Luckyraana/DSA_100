/*Implement merge sort (divide, sort halves, merge).
Print sorted array.*/

#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int temp[right - left + 1];

    i = left;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            k++;
            i++;
        } else {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        k++;
        j++;
    }

    i = left;
    k = 0;
    while (i <= right) {
        arr[i] = temp[k];
        i++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    i = 0;
    while (i < n) {
        scanf("%d", &arr[i]);
        i++;
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    i = 0;
    while (i < n) {
        printf("%d ", arr[i]);
        i++;
    }

    return 0;
}
