/*BST Search

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
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct TreeNode* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root != NULL) {
        if (root->val == val) return root;
        else if (val < root->val) root = root->left;
        else root = root->right;
    }
    return NULL;
}

void printLevelOrder(struct TreeNode* root) {
    if (root == NULL) {
        printf("NULL");
        return;
    }

    struct TreeNode* queue[5000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* curr = queue[front++];
        printf("%d ", curr->val);

        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int i = 0;
    while (i < n) {
        scanf("%d", &arr[i]);
        i++;
    }

    int val;
    scanf("%d", &val);

    struct TreeNode* root = buildTree(arr, n);
    struct TreeNode* result = searchBST(root, val);

    printLevelOrder(result);

    return 0;
}
