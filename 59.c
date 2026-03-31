/*Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int idxMap[7005];
int postIndex;

struct TreeNode* build(int* inorder, int* postorder, int inStart, int inEnd) {
    if (inStart > inEnd)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postIndex--];
    root->left = NULL;
    root->right = NULL;

    if (inStart == inEnd)
        return root;

    int pos = idxMap[root->val + 3000];

    root->right = build(inorder, postorder, pos + 1, inEnd);
    root->left = build(inorder, postorder, inStart, pos - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int i;

    for (i = 0; i < inorderSize; i++)
        idxMap[inorder[i] + 3000] = i;

    postIndex = postorderSize - 1;

    return build(inorder, postorder, 0, inorderSize - 1);
}

void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n, i;

    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    struct TreeNode* root = buildTree(inorder, n, postorder, n);

    preorder(root);

    return 0;
}

