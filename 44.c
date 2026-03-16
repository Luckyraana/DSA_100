/*Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int v){
    if(v == -1) return NULL;
    struct Node* n = malloc(sizeof(struct Node));
    n->val = v;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inorder(struct Node* root){
    if(root){
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

void preorder(struct Node* root){
    if(root){
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
    }
}

int main(){
    int n;
    scanf("%d",&n);

    int a[100];
    long long i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    struct Node* nodes[100];

    for(i=0;i<n;i++)
        nodes[i] = create(a[i]);

    for(i=0;i<n;i++){
        if(nodes[i]){
            long long l = 2*i + 1;
            long long r = 2*i + 2;
            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }

    struct Node* root = nodes[0];

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);

    return 0;
}
