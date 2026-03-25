/*Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QNode {
    struct TreeNode* node;
    int hd;
};

struct MapNode {
    int* values;
    int size;
    int capacity;
};

int main() {
    int N;
    scanf("%d", &N);
    if (N == 0) return 0;

    int* arr = (int*)malloc(sizeof(int) * N);
    int i, j;
    for (i = 0; i < N; i++) scanf("%d", &arr[i]);

    struct TreeNode** nodes = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * N);
    for (i = 0; i < N; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else {
            nodes[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            nodes[i]->val = arr[i];
            nodes[i]->left = nodes[i]->right = NULL;
        }
    }

    for (i = 0, j = 1; j < N;) {
        if (nodes[i] != NULL) {
            if (j < N) nodes[i]->left = nodes[j++];
            if (j < N) nodes[i]->right = nodes[j++];
        } else {
            i++;
            continue;
        }
        i++;
    }

    struct TreeNode* root = nodes[0];

    struct MapNode map[2000];
    for (i = 0; i < 2000; i++) {
        map[i].values = (int*)malloc(sizeof(int) * 2000);
        map[i].size = 0;
        map[i].capacity = 2000;
    }

    struct QNode* queue = (struct QNode*)malloc(sizeof(struct QNode) * N);
    int front = 0, rear = 0;
    queue[rear++] = (struct QNode){root, 1000};

    int minHD = 1000, maxHD = 1000;

    while (front < rear) {
        struct QNode qn = queue[front++];
        int hd = qn.hd;
        struct TreeNode* node = qn.node;

        map[hd].values[map[hd].size++] = node->val;

        if (node->left) {
            queue[rear++] = (struct QNode){node->left, hd - 1};
            if (hd - 1 < minHD) minHD = hd - 1;
        }
        if (node->right) {
            queue[rear++] = (struct QNode){node->right, hd + 1};
            if (hd + 1 > maxHD) maxHD = hd + 1;
        }
    }

    int k, l;
    for (k = minHD; k <= maxHD; k++) {
        for (l = 0; l < map[k].size; l++) {
            printf("%d ", map[k].values[l]);
        }
        printf("\n");
    }

    free(arr);
    free(nodes);
    free(queue);
    for (i = 0; i < 2000; i++) free(map[i].values);

    return 0;
}


