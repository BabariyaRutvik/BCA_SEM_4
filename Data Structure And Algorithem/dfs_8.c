/*
8. Implement the depth-first search (DFS) algorithm for a graph.

Explanation:
- DFS explores as far as possible along each branch before backtracking.
- Using an adjacency matrix and a visited[] array, DFS marks the current vertex
  as visited, prints it, and recursively visits all unvisited adjacent vertices.
*/
#include <stdio.h>

int graph[20][20], visited[20];

void DFS(int current, int n) {
    int i;
    visited[current] = 1;
    printf("%d ", current);

    for (i = 0; i < n; i++) {
        if (graph[current][i] == 1 && visited[i] == 0) {
            DFS(i, n);
        }
    }
}

int main() {
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start, n);
    printf("\n");

    return 0;
}

/*
Sample Input:
4
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
0

Sample Output:
Enter number of vertices: Enter Adjacency Matrix (4 x 4):
Enter starting vertex (0 to 3): DFS Traversal: 0 1 3 2
*/
