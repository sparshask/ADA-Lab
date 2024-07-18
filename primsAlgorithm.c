#include <stdio.h>
#include <limits.h> // For INT_MAX

#define MAX 100

void primsAlgorithm(int graph[MAX][MAX], int n);

int main() {
    int n, i, j;
    int graph[MAX][MAX];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0) {
                graph[i][j] = INT_MAX; // Set no edge to a large value
            }
        }
    }

    primsAlgorithm(graph, n);

    return 0;
}

void primsAlgorithm(int graph[MAX][MAX], int n) {
    int selected[MAX] = {0};
    int i, j, u, v, min;
    int edgeCount = 0;
    int minCost = 0;

    selected[0] = 1; // Start with the first vertex

    while (edgeCount < n - 1) {
        min = INT_MAX;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("Edge %d-%d: %d\n", u, v, min);
        minCost += min;
        selected[v] = 1;
        edgeCount++;
    }

    printf("Minimum cost of spanning tree: %d\n", minCost);
}
