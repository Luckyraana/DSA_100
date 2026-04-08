/*Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/

#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int *visited, int **adj, int *adjSize, int *stack, int *top) {
    visited[node] = 1;

    int i = 0;
    while (i < adjSize[node]) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj, adjSize, stack, top);
        }
        i++;
    }

    stack[(*top)++] = node;
}

void topologicalSort(int V, int **adj, int *adjSize) {
    int *visited = (int*)calloc(V, sizeof(int));
    int *stack = (int*)malloc(V * sizeof(int));
    int top = 0;

    int i = 0;
    while (i < V) {
        if (!visited[i]) {
            dfs(i, visited, adj, adjSize, stack, &top);
        }
        i++;
    }

    i = top - 1;
    while (i >= 0) {
        printf("%d ", stack[i]);
        i--;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int **adj = (int**)malloc(V * sizeof(int*));
    int *adjSize = (int*)calloc(V, sizeof(int));

    int i = 0;
    while (i < V) {
        adj[i] = (int*)malloc(V * sizeof(int));
        i++;
    }

    i = 0;
    while (i < E) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        i++;
    }

    topologicalSort(V, adj, adjSize);

    return 0;
}
