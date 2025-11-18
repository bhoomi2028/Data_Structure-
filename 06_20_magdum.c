#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int adj[SIZE][SIZE], visited[SIZE], stack[SIZE], top = -1;

void addEdge(int u, int v) {
    adj[u][v] = 1; 
}

void dfs(int node, int n) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
    stack[++top] = node;
}

void topologicalSort(int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i, n);
    }

    printf("Topological Sort Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int n, e, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        printf("Enter edge %d (u -> v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    topologicalSort(n);

    return 0;
}
