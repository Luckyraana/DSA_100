/*Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int queue[100];
    int stack[100];
    int top = -1;

    int i;

    for(i=0;i<n;i++)
        scanf("%d",&queue[i]);

    for(i=0;i<n;i++)
        stack[++top] = queue[i];

    for(i=0;i<n;i++)
        queue[i] = stack[top--];

    for(i=0;i<n;i++)
        printf("%d ",queue[i]);

    return 0;
}


