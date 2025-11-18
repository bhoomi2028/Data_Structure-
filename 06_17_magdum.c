#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int adj[SIZE][SIZE], visited[SIZE];
int queue[SIZE], front = 0, rear = 0;

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void bfs(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    front = rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfsUtil(int node, int n) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfsUtil(i, n);
        }
    }
}

void dfs(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS: ");
    dfsUtil(start, n);
    printf("\n");
}

int main() {
    int n, e, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex for traversal: ");
    scanf("%d", &start);

    bfs(start, n);
    dfs(start, n);

    return 0;
}
