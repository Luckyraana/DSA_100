/*Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    int i;

    for (i = 0; exp[i] != '\0'; i++) {

        if (exp[i] == ' ' || exp[i] == '\n')
            continue;

        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0');
        }
        else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            int result;

            switch (exp[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

int main() {
    char exp[100];
    fgets(exp, sizeof(exp), stdin);

    printf("%d\n", evaluatePostfix(exp));

    return 0;
}


