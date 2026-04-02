/*Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/

#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[200][200];

    int i = 0, j;
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            adj[i][j] = 0;
            j++;
        }
        i++;
    }

    int u, v;
    i = 0;
    while (i < m)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
        i++;
    }

    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            printf("%d ", adj[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}
