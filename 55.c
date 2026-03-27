/*Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node;
    node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    struct TreeNode* root;
    struct TreeNode* queue[1000];
    struct TreeNode* curr;
    int front, rear, i;

    if (n == 0 || arr[0] == -1) return NULL;

    root = newNode(arr[0]);
    front = 0;
    rear = 0;
    queue[rear++] = root;
    i = 1;

    while (front < rear && i < n) {
        curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void rightView(struct TreeNode* root) {
    struct TreeNode* queue[1000];
    struct TreeNode* node;
    int front, rear, size, i, rightVal;

    if (root == NULL) return;

    front = 0;
    rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        size = rear - front;
        rightVal = 0;
        i = 0;

        while (i < size) {
            node = queue[front++];

            rightVal = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;

            i++;
        }

        printf("%d ", rightVal);
    }
}

int main() {
    int n, i;
    int arr[1000];
    struct TreeNode* root;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    root = buildTree(arr, n);
    rightView(root);

    return 0;
}

