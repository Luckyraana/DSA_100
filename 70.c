#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, struct Edge edges[], int src) {
    int dist[100];
    int i, j;

    for (i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (i = 1; i <= n - 1; i++) {
        for (j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    for (i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    printf("\n");
}

int main() {
    int n, m, i, src;

    scanf("%d %d", &n, &m);

    struct Edge edges[100];

    for (i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    scanf("%d", &src);

    bellmanFord(n, m, edges, src);

    return 0;
}
