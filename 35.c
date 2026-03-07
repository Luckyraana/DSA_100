/*Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int front;
    int rear;
    int size;
}Queue;

void enqueue(Queue *q,int x)
{
    if(q->rear==q->size-1)
        return;

    if(q->front==-1)
        q->front=0;

    q->arr[++q->rear]=x;
}

void display(Queue *q)
{
    int i;

    for(i=q->front;i<=q->rear;i++)
        printf("%d ",q->arr[i]);
}

int main()
{
    int n,i,x;

    scanf("%d",&n);

    Queue q;

    q.size=n;
    q.front=-1;
    q.rear=-1;

    q.arr=(int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(&q,x);
    }

    display(&q);

    free(q.arr);

    return 0;
}


