#include <stdio.h>

int G[20][20], visited[20], n;

void dfs(int v)
{
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (G[v][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int edges, u, v, start;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &edges);

    // Initialize graph and visited array
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            G[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;   // Undirected graph
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}
