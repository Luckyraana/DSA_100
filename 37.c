/*Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empt*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x)
{
    int i;

    if(size == MAX)
        return;

    i = size - 1;

    while(i >= 0 && pq[i] > x)
    {
        pq[i+1] = pq[i];
        i--;
    }

    pq[i+1] = x;
    size++;
}

int delete()
{
    int val;
    int i;

    if(size == 0)
        return -1;

    val = pq[0];

    for(i = 1; i < size; i++)
        pq[i-1] = pq[i];

    size--;

    return val;
}

int peek()
{
    if(size == 0)
        return -1;

    return pq[0];
}

int main()
{
    int n, x, i;
    char op[10];

    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        scanf("%s",op);

        if(strcmp(op,"insert") == 0)
        {
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"delete") == 0)
        {
            printf("%d\n",delete());
        }
        else if(strcmp(op,"peek") == 0)
        {
            printf("%d\n",peek());
        }
    }

    return 0;
}


