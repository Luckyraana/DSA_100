/* Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

typedef struct {
    int v, dist;
} HeapNode;

typedef struct {
    int size;
    HeapNode arr[MAX * MAX];
} MinHeap;

Node* adj[MAX];

MinHeap* createHeap() {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->size = 0;
    return h;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void push(MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->arr[i].v = v;
    h->arr[i].dist = dist;

    while (i && h->arr[i].dist < h->arr[(i - 1) / 2].dist) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(MinHeap* h) {
    HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];

    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;

        if (l < h->size && h->arr[l].dist < h->arr[smallest].dist)
            smallest = l;
        if (r < h->size && h->arr[r].dist < h->arr[smallest].dist)
            smallest = r;

        if (smallest != i) {
            swap(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else break;
    }

    return root;
}

void addEdge(int u, int v, int w) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->v = v;
    temp->w = w;
    temp->next = adj[u];
    adj[u] = temp;
}

void dijkstra(int n, int src) {
    int dist[MAX];
    int i;

    for (i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    MinHeap* h = createHeap();
    dist[src] = 0;
    push(h, src, 0);

    while (h->size > 0) {
        HeapNode top = pop(h);
        int u = top.v;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
}

int main() {
    int n, e, i;
    scanf("%d %d", &n, &e);

    for (i = 1; i <= n; i++)
        adj[i] = NULL;

    for (i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}
