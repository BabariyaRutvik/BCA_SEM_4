/*
59. To implement a program to represent a graph using an adjacency matrix and an adjacency list, and calculate the degree of each vertex.

Explanation:
- Reads an undirected graph with V vertices and E edges.
- Builds both an Adjacency Matrix adjMat[V][V] and an Adjacency List adjList[V].
- Calculates and displays each vertex's degree (number of incident edges).
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXV 20

struct AdjNode {
    int dest;
    struct AdjNode *next;
};

int adjMat[MAXV][MAXV];
struct AdjNode *adjList[MAXV];

void addEdgeList(int u, int v) {
    struct AdjNode *node = (struct AdjNode *)malloc(sizeof(struct AdjNode));
    node->dest = v;
    node->next = adjList[u];
    adjList[u] = node;
}

int main() {
    int v, e, i, j, src, dest;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &v, &e);

    for (i = 0; i < v; i++) {
        adjList[i] = NULL;
        for (j = 0; j < v; j++) {
            adjMat[i][j] = 0;
        }
    }

    printf("Enter %d undirected edges (u v) with vertices 0 to %d:\n", e, v - 1);
    for (i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        adjMat[src][dest] = 1;
        adjMat[dest][src] = 1;
        addEdgeList(src, dest);
        addEdgeList(dest, src);
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            printf("%d ", adjMat[i][j]);
        }
        printf("\n");
    }

    printf("\nAdjacency List:\n");
    for (i = 0; i < v; i++) {
        struct AdjNode *temp = adjList[i];
        printf("Vertex %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    printf("\nDegree of each vertex:\n");
    for (i = 0; i < v; i++) {
        int degree = 0;
        for (j = 0; j < v; j++) {
            degree += adjMat[i][j];
        }
        printf("Degree(%d) = %d\n", i, degree);
    }

    return 0;
}

/*
Sample Input:
4 4
0 1
0 2
1 2
2 3

Sample Output:
Enter number of vertices and edges: Enter 4 undirected edges (u v) with vertices 0 to 3:

Adjacency Matrix:
0 1 1 0 
1 0 1 0 
1 1 0 1 
0 0 1 0 

Adjacency List:
Vertex 0: 2 -> 1 -> NULL
Vertex 1: 2 -> 0 -> NULL
Vertex 2: 3 -> 1 -> 0 -> NULL
Vertex 3: 2 -> NULL

Degree of each vertex:
Degree(0) = 2
Degree(1) = 2
Degree(2) = 3
Degree(3) = 1
*/
