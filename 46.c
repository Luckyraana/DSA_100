/*Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* queue[n];
    size_t front = 0, rear = 0;

    struct TreeNode* root = createNode(arr[0]);
    queue[rear++] = root;

    size_t i = 1;

    while (i < (size_t)n) {
        struct TreeNode* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < (size_t)n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void levelOrder(struct TreeNode* root) {
    if (!root)
        return;

    struct TreeNode* queue[2000];
    size_t front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        size_t size = rear - front;

        while (size--) {
            struct TreeNode* node = queue[front++];
            printf("%d ", node->val);

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    size_t i = 0;
    while (i < (size_t)n) {
        scanf("%d", &arr[i]);
        i++;
    }

    struct TreeNode* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}
