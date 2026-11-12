# 2. Implement a Python function to perform depth-first search on a given state space.

# creatibg graph using adjency list
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': [],
    'F': [],
    'G': []
}

# DFS function
def dfs(graph, start, visited=None):

    if visited is None:
        visited = set()

        # mark current node as visited
    visited.add(start)
    print(start, end=' ')

    # visited all connected nodes
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

# Start DFS from node 'A'.
print("DFS Traversal :")
visited = set()
for node in graph:
    if node not in visited:
        dfs(graph, node, visited)
print()