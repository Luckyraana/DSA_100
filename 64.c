/*Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/

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

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void BFS(struct Node* adj[], int n, int s) {
    int visited[n];
    int queue[n];
    int front = 0, rear = 0;

    int i = 0;
    while (i < n) {
        visited[i] = 0;
        i++;
    }

    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        struct Node* temp = adj[node];
        while (temp != NULL) {
            int v = temp->data;
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m, s;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];

    int i = 0;
    while (i < n) {
        adj[i] = NULL;
        i++;
    }

    int j = 0;
    while (j < m) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
        j++;
    }

    scanf("%d", &s);

    BFS(adj, n, s);

    return 0;
}
