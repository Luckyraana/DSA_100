/*Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

int search(int inorder[], int start, int end, int key) {
    for (; start <= end; start++) {
        if (inorder[start] == key)
            return start;
    }
    return -1;
}

struct Node* build(int preorder[], int inorder[], int start, int end, int *preIndex) {
    if (start > end)
        return NULL;

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->val = preorder[*preIndex];
    root->left = NULL;
    root->right = NULL;

    (*preIndex)++;

    if (start == end)
        return root;

    int pos = search(inorder, start, end, root->val);

    root->left = build(preorder, inorder, start, pos - 1, preIndex);
    root->right = build(preorder, inorder, pos + 1, end, preIndex);

    return root;
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n, i;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    i = 0;
    for (; i < n; i++)
        scanf("%d", &preorder[i]);

    i = 0;
    for (; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = build(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}


