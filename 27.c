/*Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

struct Node* getNodeByValue(struct Node* head, int value) {
    while (head != NULL) {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1, len2, diff, i;
    struct Node *ptr1, *ptr2;

    len1 = getLength(head1);
    len2 = getLength(head2);

    ptr1 = head1;
    ptr2 = head2;

    if (len1 > len2) {
        diff = len1 - len2;
        i = 0;
        while (i < diff) {
            ptr1 = ptr1->next;
            i++;
        }
    } else {
        diff = len2 - len1;
        i = 0;
        while (i < diff) {
            ptr2 = ptr2->next;
            i++;
        }
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m, i, value;
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *intersectionNode, *connectPoint, *temp;

   
    scanf("%d", &n);
    i = 0;
    while (i < n) {
        scanf("%d", &value);
        insertEnd(&head1, value);
        i++;
    }

   
    scanf("%d", &m);
    i = 0;
    while (i < m) {
        scanf("%d", &value);
        insertEnd(&head2, value);
        i++;
    }


    temp = head2;
    while (temp != NULL) {
        connectPoint = getNodeByValue(head1, temp->data);
        if (connectPoint != NULL) {
            break;
        }
        temp = temp->next;
    }

    if (temp != NULL) {
        struct Node* last = head2;
        while (last->next != NULL)
            last = last->next;
        last->next = connectPoint;
    }

    intersectionNode = findIntersection(head1, head2);

    if (intersectionNode != NULL)
        printf("%d\n", intersectionNode->data);
    else
        printf("No Intersection\n");

    return 0;
}
