/*Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated*/

#include <stdio.h>

int main()
{
    int n,m,i;

    scanf("%d",&n);

    int a[n];

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    scanf("%d",&m);

    int front=m % n;

    for(i=0;i<n;i++)
    {
        printf("%d ",a[(front+i)%n]);
    }

    return 0;
}


