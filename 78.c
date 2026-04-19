/*Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST*/

#include <stdio.h>
#include <limits.h>

#define MAX 1005

int graph[MAX][MAX];

int minKey(int key[], int vis[], int n) {
    int min = INT_MAX, index = -1;
    int i;
    for (i = 1; i <= n; i++) {
        if (!vis[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int n, m;
    int i, j;
    int u, v, w;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[MAX], vis[MAX];

    for (i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        vis[i] = 0;
    }

    key[1] = 0;

    int total = 0;

    for (i = 1; i <= n; i++) {
        u = minKey(key, vis, n);
        vis[u] = 1;
        total += key[u];

        for (v = 1; v <= n; v++) {
            if (graph[u][v] && !vis[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", total);

    return 0;
}


