#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], disc[MAX], low[MAX], parent[MAX];
int timeCounter = 0, isArticulationFound = 0;

void addEdge(int u, int v) {
    adj[u][v] = adj[v][u] = 1;
}

void DFS(int u, int n) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;
    int children = 0;

    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                DFS(v, n);

                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                if ((parent[u] == -1 && children > 1) || 
                    (parent[u] != -1 && low[v] >= disc[u])) {
                    isArticulationFound = 1;
                }
            } else if (v != parent[u]) {
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
            }
        }
    }
}

int isBiconnected(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    DFS(0, n);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) return 0; 
    }

    return !isArticulationFound;
}

int main() {
    int n, e, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    if (isBiconnected(n))
        printf("The graph is BICONNECTED\n");
    else
        printf("The graph is NOT biconnected\n");

    return 0;
}
