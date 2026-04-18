/*Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED*/

#include <stdio.h>
#include <stdlib.h>

void dfs(int u, int* visited, int** adj, int* adjSize) {
    int i, v;
    visited[u] = 1;
    for (i = 0; i < adjSize[u]; i++) {
        v = adj[u][i];
        if (!visited[v]) dfs(v, visited, adj, adjSize);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int i, u, v;

    int* adjSize = (int*)calloc(n + 1, sizeof(int));
    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    int** edges = (int**)malloc(m * sizeof(int*));

    for (i = 0; i < m; i++) {
        edges[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &u, &v);
        edges[i][0] = u;
        edges[i][1] = v;
        adjSize[u]++;
        adjSize[v]++;
    }

    for (i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    for (i = 0; i < m; i++) {
        u = edges[i][0];
        v = edges[i][1];
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int* visited = (int*)calloc(n + 1, sizeof(int));

    dfs(1, visited, adj, adjSize);

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}

