/*Implement topological sorting using in-degree array and queue (Kahn’s Algorithm).*/

#include <stdio.h>
#define MAX 100

int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void topoSort(int V, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    int i, j, count = 0;

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    for (i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (j = 0; j < V; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }

    if (count != V) {
        printf("\nCycle detected");
    }
}

int main() {
    int V, E, i, u, v;
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};

    for (i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topoSort(V, adj);

    return 0;
}
