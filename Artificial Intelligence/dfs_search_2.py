# 2. Implement a Python function to perform depth-first search on a given state space.
"""
Use: Used to explore graphs, mazes, and state spaces by following each branch as deep as possible.
Process: Starting from a node, DFS marks it visited and recursively explores each unvisited neighbor.
When it hits a dead end, it backtracks to check remaining neighbors.
An outer loop over all graph nodes ensures disconnected nodes are also visited.
"""

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

"""
Output:
DFS Traversal :
A B D E C F G
"""