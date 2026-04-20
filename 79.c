/*Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.*/

#include <stdio.h>

#define MAX 200   // reduced to avoid Dev C++ crash
#define INF 999999

int minDistance(int dist[], int visited[], int n) {
    int min = INF;
    int min_index = -1;
    int i;

    for (i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int n, int graph[MAX][MAX], int src) {
    int dist[MAX];
    int visited[MAX] = {0};
    int i;

    for (i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[src] = 0;

    int count, v;

    for (count = 1; count <= n - 1; count++) {
        int u = minDistance(dist, visited, n);

        if (u == -1) return;

        visited[u] = 1;

        for (v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m, i;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX] = {0};

    for (i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, graph, src);

    return 0;
}
