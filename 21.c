/*Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    
    int n;
    scanf("%d", &n);
    
    if (n <= 0)
        return 0;
    
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;
    int i;   
    
    scanf("%d", &value);
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->next = NULL;
    
    temp = head;
    
    i = 1;
    while (i < n) {
        scanf("%d", &value);
        
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        
        temp->next = newNode;
        temp = newNode;
        
        i++;
    }
    
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    return 0;
}


