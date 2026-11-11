/*
37. To implement Kruskal's Algorithm to find the Minimum Spanning Tree (MST) of a given graph.

Explanation:
- Kruskal's Algorithm sorts all edges in ascending order of weight.
- Using Disjoint Set Union (find/union), it adds the smallest edge that does not
  form a cycle (i.e., endpoints belong to different sets) until (V - 1) edges are chosen.
*/
#include <stdio.h>
#define MAXE 100
#define MAXV 20

struct Edge {
    int u, v, w;
};

int parent[MAXV];

int findSet(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void unionSet(int a, int b) {
    int rootA = findSet(a);
    int rootB = findSet(b);
    parent[rootA] = rootB;
}

int main() {
    struct Edge edges[MAXE], temp;
    int v, e, i, j, count = 0, totalCost = 0;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &v, &e);

    printf("Enter edges (u v weight) with vertices 0 to %d:\n", v - 1);
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    /* Sort edges by ascending weight */
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - 1 - i; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < v; i++) {
        parent[i] = i;
    }

    printf("\nEdges in Minimum Spanning Tree (Kruskal's):\n");
    for (i = 0; i < e && count < v - 1; i++) {
        int setU = findSet(edges[i].u);
        int setV = findSet(edges[i].v);
        if (setU != setV) {
            printf("Edge (%d - %d) : Weight = %d\n", edges[i].u, edges[i].v, edges[i].w);
            totalCost += edges[i].w;
            unionSet(setU, setV);
            count++;
        }
    }

    printf("Total Minimum Spanning Tree Cost = %d\n", totalCost);
    return 0;
}

/*
Sample Input:
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Sample Output:
Enter number of vertices and edges: Enter edges (u v weight) with vertices 0 to 3:

Edges in Minimum Spanning Tree (Kruskal's):
Edge (2 - 3) : Weight = 4
Edge (0 - 3) : Weight = 5
Edge (0 - 1) : Weight = 10
Total Minimum Spanning Tree Cost = 19
*/
