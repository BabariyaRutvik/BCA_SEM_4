# 39. Implement a pathfinding algorithm (like A* or Dijkstra's) to find the shortest path in a maze/grid.
"""
Use: Used in GPS navigation, game AI, and warehouse robots to find the shortest obstacle-free route.
Process: A* search maintains a priority queue ordered by f(n) = g(n) + h(n), where g is cost from start
and h is Manhattan distance to the goal. It expands the lowest-f cell and skips walls (1).
Once the goal cell is popped, it returns the shortest path from start to goal.
"""

import heapq


def astar_maze(grid, start, goal):
    rows, cols = len(grid), len(grid[0])

    def heuristic(a, b):
        return abs(a[0] - b[0]) + abs(a[1] - b[1])

    pq = [(heuristic(start, goal), 0, start, [start])]
    visited = set()

    while pq:
        f, g, current, path = heapq.heappop(pq)
        if current == goal:
            return path
        if current in visited:
            continue
        visited.add(current)

        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nr, nc = current[0] + dr, current[1] + dc
            if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 0 and (nr, nc) not in visited:
                new_g = g + 1
                heapq.heappush(pq, (new_g + heuristic((nr, nc), goal), new_g, (nr, nc), path + [(nr, nc)]))

    return None


# Real-life example: Warehouse floor grid (0 = aisle, 1 = storage rack)
warehouse_grid = [
    [0, 0, 0, 1, 0],
    [1, 1, 0, 1, 0],
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 0]
]

start_cell = (0, 0)
goal_cell = (4, 4)
shortest_path = astar_maze(warehouse_grid, start_cell, goal_cell)

print("Start:", start_cell, "Goal:", goal_cell)
print("Shortest Path:", shortest_path)
print("Total Steps:", len(shortest_path) - 1)

"""
Output:
Start: (0, 0) Goal: (4, 4)
Shortest Path: [(0, 0), (0, 1), (0, 2), (1, 2), (2, 2), (2, 3), (2, 4), (3, 4), (4, 4)]
Total Steps: 8
"""
