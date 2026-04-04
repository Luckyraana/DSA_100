/*Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node** adj, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(struct Node** adj, int* visited, int s) {
    printf("%d ", s);
    visited[s] = 1;

    struct Node* temp = adj[s];

    while (temp) {
        if (!visited[temp->data]) {
            dfs(adj, visited, temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, u, v, s;

    scanf("%d", &n);
    scanf("%d", &m);

    struct Node** adj = (struct Node**)malloc(n * sizeof(struct Node*));
    int* visited = (int*)calloc(n, sizeof(int));

    int i = 0;
    while (i < n) {
        adj[i] = NULL;
        i++;
    }

    i = 0;
    while (i < m) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
        i++;
    }

    scanf("%d", &s);

    dfs(adj, visited, s);

    return 0;
}
