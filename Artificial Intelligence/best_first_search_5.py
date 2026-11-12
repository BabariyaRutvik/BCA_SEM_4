
# 5. Implement a Python function to perform best-first search on a problem space.
"""
Use: Used in pathfinding and routing when a heuristic estimate guides which node to explore next.
Process: A priority queue stores nodes ordered by their heuristic value h(n) (estimated distance to goal).
At each step, the node with the lowest heuristic is popped and checked against the goal.
If not the goal, its unvisited neighbors are pushed to the queue until the goal path is found.
"""

import heapq

# Create a graph
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': [],
    'E': [],
    'F': [],
    'G': []
}

# Heuristic values
heuristic = {
    'A': 10,
    'B': 6,
    'C': 4,
    'D': 7,
    'E': 2,
    'F': 5,
    'G': 0
}

# Best-First Search function
def best_first_search(start, goal):

    # Priority queue stores (heuristic, node, path)
    priority_queue = [(heuristic[start], start, [start])]

    visited = set()

    while priority_queue:

        h, current, path = heapq.heappop(priority_queue)

        if current in visited:
            continue

        visited.add(current)

        print("Visiting:", current)

        # Check whether goal is reached
        if current == goal:
            return path

        # Explore neighbouring nodes
        for neighbour in graph[current]:

            if neighbour not in visited:
                heapq.heappush(
                    priority_queue,
                    (heuristic[neighbour],
                     neighbour,
                     path + [neighbour])
                )

    return None


# Start the search
result = best_first_search('A', 'G')

print("\nPath to Goal:", result)

"""
Output:
Visiting: A
Visiting: C
Visiting: G

Path to Goal: ['A', 'C', 'G']
"""
