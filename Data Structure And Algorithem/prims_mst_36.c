/*
36. To implement Prim's Algorithm to find the Minimum Spanning Tree (MST) of a given graph.

Explanation:
- Prim's Algorithm grows an MST starting from vertex 0.
- At each step, it picks the minimum-weight edge connecting a visited vertex (in MST)
  to an unvisited vertex, adds that vertex to the MST, and repeats for (V - 1) edges.
- Enter 0 in the adjacency matrix when there is no edge between two vertices.
*/
#include <stdio.h>
#define MAX 20
#define INF 999999

int main() {
    int n, i, j, k;
    int cost[MAX][MAX], visited[MAX];
    int edges = 0, totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter Cost Adjacency Matrix (0 if no edge):\n");
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }

    visited[0] = 1;
    printf("\nEdges in Minimum Spanning Tree (Prim's):\n");

    while (edges < n - 1) {
        int min = INF, u = -1, v = -1;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (u != -1 && v != -1) {
            printf("Edge (%d - %d) : Weight = %d\n", u, v, min);
            totalCost += min;
            visited[v] = 1;
            edges++;
        } else {
            printf("Graph is disconnected; MST cannot span all vertices.\n");
            break;
        }
    }

    printf("Total Minimum Spanning Tree Cost = %d\n", totalCost);
    k = 0; (void)k;
    return 0;
}

/*
Sample Input:
4
0 2 0 6
2 0 3 8
0 3 0 0
6 8 0 0

Sample Output:
Enter number of vertices: Enter Cost Adjacency Matrix (0 if no edge):

Edges in Minimum Spanning Tree (Prim's):
Edge (0 - 1) : Weight = 2
Edge (1 - 2) : Weight = 3
Edge (0 - 3) : Weight = 6
Total Minimum Spanning Tree Cost = 11
*/
