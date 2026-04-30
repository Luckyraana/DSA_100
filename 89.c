/*Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

*/

#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int currentSum = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (currentSum + arr[i] > maxPages) {
            students++;
            currentSum = arr[i];
        } else {
            currentSum += arr[i];
        }
    }

    return (students <= m);
}

int allocateBooks(int arr[], int n, int m) {
    int low = 0, high = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    int mid;
    int ans = high;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, m;
    int i;

    scanf("%d %d", &n, &m);

    int arr[1000];  // safe fixed size for Dev C++

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d", allocateBooks(arr, n, m));

    return 0;
}
