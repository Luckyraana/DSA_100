/*Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1005

int visited[MAXN];
int adj[MAXN][MAXN];
int deg[MAXN];

void dfs(int node) {
    visited[node] = 1;

    int i, v;

    for (i = 0; i < deg[node]; i++) {
        v = adj[node][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int i, u, v, components;

    for (i = 1; i <= n; i++) {
        deg[i] = 0;
        visited[i] = 0;
    }

    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    components = 0;

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);

    return 0;
}


