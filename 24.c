/*Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* deleteKey(struct Node* head, int key) {
    
    struct Node *temp = head, *prev = NULL;

   
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

   
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

 
    if (temp == NULL)
        return head;

  
    prev->next = temp->next;
    free(temp);

    return head;
}

int main() {
    int n, i, value, key;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

   
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &key);

    head = deleteKey(head, key);

   
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}


