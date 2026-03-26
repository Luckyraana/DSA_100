/*Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    struct TreeNode* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n && front < rear) {
        struct TreeNode* node = queue[front++];

        if (i < n && arr[i] != -1) {
            node->left = newNode(arr[i]);
            queue[rear++] = node->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            node->right = newNode(arr[i]);
            queue[rear++] = node->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void zigzagPrint(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode** queue = (struct TreeNode**)malloc(1000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;
    int i;

    while (front < rear) {
        int size = rear - front;
        int* arr = (int*)malloc(size * sizeof(int));

        for (i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            arr[i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        if (leftToRight) {
            for (i = 0; i < size; i++)
                printf("%d ", arr[i]);
        } else {
            for (i = size - 1; i >= 0; i--)
                printf("%d ", arr[i]);
        }

        free(arr);
        leftToRight = !leftToRight;
    }

    free(queue);
}

int main() {
    int n, i;

    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    zigzagPrint(root);

    return 0;
}
