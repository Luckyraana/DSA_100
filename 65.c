/*Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int parent, int visited[], int **adj, int *size) {
    visited[node] = 1;

    int i = 0;
    while (i < size[node]) {
        int v = adj[node][i];

        if (!visited[v]) {
            if (dfs(v, node, visited, adj, size))
                return 1;
        } else if (v != parent) {
            return 1;
        }
        i++;
    }
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int **adj = (int**)malloc(V * sizeof(int*));
    int *size = (int*)calloc(V, sizeof(int));

    int i = 0;
    while (i < V) {
        adj[i] = (int*)malloc(V * sizeof(int));
        i++;
    }

    int j = 0;
    while (j < E) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
        j++;
    }

    int *visited = (int*)calloc(V, sizeof(int));

    int s = 0;
    while (s < V) {
        if (!visited[s]) {
            if (dfs(s, -1, visited, adj, size)) {
                printf("YES");
                return 0;
            }
        }
        s++;
    }

    printf("NO");
    return 0;
}
