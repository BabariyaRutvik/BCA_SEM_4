/*
2. Implement the breadth-first search (BFS) algorithm for a graph.

Explanation:
- BFS explores a graph level by level starting from a given source vertex using a queue.
- Each visited vertex is marked in visited[] so no vertex is processed more than once.
*/
#include<stdio.h>

int graph[10][10], visited[10];
int queue[10];
int front = 0 , rear = -1;

void BFS(int start , int n){
	int i;
	visited[start] = 1;
	queue[++rear] = start;
	
	while (front <= rear){
		int current = queue[front++];
		
		printf("%d", current);
		
		for (i = 0; i<n ; i++){
			if(graph[current][i] == 1 && visited[i] == 0){
				visited[i] = 1;
				queue[++rear] = i;
				
			}
		}
	}
}

int main(){
	
	int n, i , j , start;
	printf("Enter Number of Verties:");
	scanf("%d", &n);
	
	printf("Enter Adjacency Matrix:\n");
	
	for(i = 0; i < n; i++){
		for( j = 0; j < n; j++){
			scanf("%d", &graph[i][j]);
		}
	}
	
	printf("Enter starting vertex: ");
	scanf("%d", &start);
	
	printf("BFS Traversal:v ");
	BFS(start, n);
	
	
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
Enter Number of Verties:Enter Adjacency Matrix:
Enter starting vertex: BFS Traversal:v 0123
*/
