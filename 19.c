/*Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    int i;
    
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    
    qsort(arr, n, sizeof(int), compare);
    
    int left = 0;
    int right = n - 1;
    
    int minSum = 1000000000;  
    int num1 = arr[0], num2 = arr[1];
    
    
    while(left < right) {
        int sum = arr[left] + arr[right];
        
        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            num1 = arr[left];
            num2 = arr[right];
        }
        
        if(sum < 0)
            left++;
        else
            right--;
    }
    
    printf("%d %d", num1, num2);
    
    return 0;
}


