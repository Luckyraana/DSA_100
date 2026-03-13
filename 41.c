/*Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if(rear == NULL){
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue(){
    if(front == NULL){
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", front->data);
    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

int main(){
    int n;
    int i;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        int type;
        scanf("%d",&type);

        if(type==1){
            int x;
            scanf("%d",&x);
            enqueue(x);
        }
        else if(type==2){
            dequeue();
        }
    }
}
