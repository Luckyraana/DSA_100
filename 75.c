/*Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.*/

#include <stdio.h>

int maxLenZeroSum(int arr[], int n) {
    int maxLen = 0, sum = 0;
    int i = 0, j = 0;

    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0 && (j - i + 1 > maxLen)) {
                maxLen = j - i + 1;
            }
        }
    }
    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLenZeroSum(arr, n));
    return 0;
}


