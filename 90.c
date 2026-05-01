/*Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.*/

#include <stdio.h>

int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int current = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (current + boards[i] > maxTime) {
            painters++;
            current = boards[i];
        } else {
            current += boards[i];
        }
    }

    return painters <= k;
}

int minTime(int boards[], int n, int k) {
    int low = boards[0], high = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    int answer = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    int n, k;
    int i;

    scanf("%d %d", &n, &k);

    int boards[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d", minTime(boards, n, k));

    return 0;
}
