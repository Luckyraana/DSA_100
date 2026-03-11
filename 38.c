/*Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)*/

#include <stdio.h>
#define MAX 1000

int deque[MAX];
int front = -1;
int rear = -1;

int empty()
{
    if(front == -1)
        return 1;
    return 0;
}

int size()
{
    if(front == -1)
        return 0;
    return rear - front + 1;
}

void push_front(int value)
{
    if(front == -1)
    {
        front = 0;
        rear = 0;
        deque[front] = value;
    }
    else if(front > 0)
    {
        front--;
        deque[front] = value;
    }
}

void push_back(int value)
{
    if(front == -1)
    {
        front = 0;
        rear = 0;
        deque[rear] = value;
    }
    else
    {
        rear++;
        deque[rear] = value;
    }
}

void pop_front()
{
    if(front == -1)
        return;

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front++;
}

void pop_back()
{
    if(front == -1)
        return;

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        rear--;
}

int get_front()
{
    if(front == -1)
        return -1;
    return deque[front];
}

int get_back()
{
    if(front == -1)
        return -1;
    return deque[rear];
}

void clear()
{
    front = -1;
    rear = -1;
}

void reverse()
{
    int i = front;
    int j = rear;
    while(i < j)
    {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

void sort()
{
    int i = front;
    int j;

    while(i <= rear)
    {
        j = i + 1;
        while(j <= rear)
        {
            if(deque[i] > deque[j])
            {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
            j++;
        }
        i++;
    }
}

void display()
{
    int i = front;
    while(i <= rear)
    {
        printf("%d ", deque[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    push_back(5);
    push_back(2);
    push_front(8);
    push_back(1);

    display();

    pop_front();
    pop_back();

    display();

    printf("%d\n", get_front());
    printf("%d\n", get_back());
    printf("%d\n", size());

    reverse();
    display();

    sort();
    display();

    clear();

    printf("%d\n", empty());
}


