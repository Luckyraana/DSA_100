/*Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int isHeap(struct TreeNode* root) {
    if (root == NULL)
        return 1;

    if (root->left == NULL && root->right == NULL)
        return 1;

    if (root->right == NULL)
        return (root->val <= root->left->val) && isHeap(root->left);

    if (root->val <= root->left->val && root->val <= root->right->val)
        return isHeap(root->left) && isHeap(root->right);

    return 0;
}

int isComplete(struct TreeNode* root, int index, int n) {
    if (root == NULL)
        return 1;

    if (index >= n)
        return 0;

    return isComplete(root->left, 2*index + 1, n) &&
           isComplete(root->right, 2*index + 2, n);
}

int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int isMinHeap(struct TreeNode* root) {
    int n = countNodes(root);

    if (isComplete(root, 0, n) && isHeap(root))
        return 1;

    return 0;
}

struct TreeNode* buildTree(int arr[], int n, int i) {
    if (i >= n)
        return NULL;

    struct TreeNode* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    int i = 0;

    while (i < n) {
        scanf("%d", &arr[i]);
        i++;
    }

    struct TreeNode* root = buildTree(arr, n, 0);

    if (isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}


