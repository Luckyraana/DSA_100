/*Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square 
is less than or equal to the given number. 
Input: - First line: an integer n 
Output: - Print the integer square root of n*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0 || n == 1) {
        printf("%d", n);
        return 0;
    }

    int left = 0, right = n, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= n / mid) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%d", ans);
    return 0;
}
