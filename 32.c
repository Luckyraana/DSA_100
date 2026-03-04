/*Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom*/

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;


void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

int main() {
    int n, m, i, value;

    scanf("%d", &n);

   
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    scanf("%d", &m);

   
    for (i = 0; i < m; i++) {
        pop();
    }

  
    while (top != -1) {
        printf("%d\n", stack[top]);
        top--;
    }

    return 0;
}


