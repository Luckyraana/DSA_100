/*Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(size_t node, int** adj, size_t* adjSize, bool* visited, bool* recStack) {
    visited[node] = true;
    recStack[node] = true;

    size_t i = 0;
    while (i < adjSize[node]) {
        size_t neigh = adj[node][i];

        if (!visited[neigh]) {
            if (dfs(neigh, adj, adjSize, visited, recStack))
                return true;
        }
        else if (recStack[neigh]) {
            return true;
        }
        i++;
    }

    recStack[node] = false;
    return false;
}

int main() {
    size_t n, m;
    scanf("%zu %zu", &n, &m);

    int** adj = (int**)malloc(n * sizeof(int*));
    size_t* adjSize = (size_t*)calloc(n, sizeof(size_t));

    size_t i = 0;
    while (i < n) {
        adj[i] = (int*)malloc(n * sizeof(int));
        i++;
    }

    i = 0;
    while (i < m) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        i++;
    }

    bool* visited = (bool*)calloc(n, sizeof(bool));
    bool* recStack = (bool*)calloc(n, sizeof(bool));

    i = 0;
    while (i < n) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack)) {
                printf("YES");
                return 0;
            }
        }
        i++;
    }

    printf("NO");
    return 0;
}
