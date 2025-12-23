#include <stdio.h>

int G[20][20], visited[20], q[20];
int n, f = 0, r = -1;

void bfs(int start)
{
    q[++r] = start;
    visited[start] = 1;

    while (f <= r)
    {
        int curr = q[f++];
        printf("%d ", curr);

        for (int i = 1; i <= n; i++)
        {
            if (G[curr][i] == 1 && !visited[i])
            {
                q[++r] = i;
                visited[i] = 1;
            }
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
        G[v][u] = 1;
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
