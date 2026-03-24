/*Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    if (val == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root) return NULL;
    if (root == p || root == q) return root;
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    struct TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

int main() {
    int N;
    scanf("%d", &N);
    int *arr = (int*)malloc(N * sizeof(int));
    int *ptr = arr;
    while (ptr - arr < N) scanf("%d", ptr++);

    struct TreeNode **queue = (struct TreeNode**)malloc(N * sizeof(struct TreeNode*));
    struct TreeNode* root = createNode(arr[0]);
    int front = 0, rear = 0;
    queue[rear++] = root;
    ptr = arr + 1;
    
    while (ptr - arr < N) {
        struct TreeNode* curr = queue[front++];
        if (!curr) continue;
        if (ptr - arr < N) {
            curr->left = createNode(*ptr++);
            if (curr->left) queue[rear++] = curr->left;
        }
        if (ptr - arr < N) {
            curr->right = createNode(*ptr++);
            if (curr->right) queue[rear++] = curr->right;
        }
    }
    
    int val1, val2;
    scanf("%d %d", &val1, &val2);
    struct TreeNode* p = findNode(root, val1);
    struct TreeNode* q = findNode(root, val2);
    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    printf("%d\n", lca->val);
    return 0;
}


