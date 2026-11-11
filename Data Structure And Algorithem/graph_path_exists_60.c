/*
60. To implement a program to detect whether a path exists between two vertices of a graph using BFS or DFS.

Explanation:
- Uses Breadth-First Search (BFS) starting from source vertex u.
- Marks visited vertices in visited[] and explores neighbors layer by layer.
- If target vertex v is reached during traversal, a path exists; otherwise no path exists.
*/
#include <stdio.h>
#define MAX 20

int graph[MAX][MAX], visited[MAX], queue[MAX];

int hasPathBFS(int n, int src, int dest) {
    int front = 0, rear = -1, i;
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[src] = 1;
    queue[++rear] = src;

    while (front <= rear) {
        int curr = queue[front++];
        if (curr == dest) {
            return 1;
        }
        for (i = 0; i < n; i++) {
            if (graph[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    return 0;
}

int main() {
    int n, i, j, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source and destination vertices (0 to %d): ", n - 1);
    scanf("%d %d", &src, &dest);

    if (hasPathBFS(n, src, dest)) {
        printf("YES, a path exists between vertex %d and vertex %d.\n", src, dest);
    } else {
        printf("NO path exists between vertex %d and vertex %d.\n", src, dest);
    }

    return 0;
}

/*
Sample Input:
4
0 1 0 0
1 0 1 0
0 1 0 0
0 0 0 0
0 2

Sample Output:
Enter number of vertices: Enter Adjacency Matrix (4 x 4):
Enter source and destination vertices (0 to 3): YES, a path exists between vertex 0 and vertex 2.
*/
