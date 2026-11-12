# 44. Write a Python program to implement A* search on a graph using a heuristic function, and compare it with greedy best-first search in terms of path cost and nodes expanded.
"""
Use: Used in route planning and GPS navigation to compare optimal pathfinding (A*) against fast heuristic search (Greedy).
Process: A* expands nodes using f(n) = g(n) + h(n), balancing actual distance traveled and estimated distance left.
Greedy Best-First Search expands nodes using only h(n), ignoring path cost so far.
Running both on the same city road graph compares their total path cost and number of nodes expanded.
"""

import heapq

# Weighted road network: node -> [(neighbor, road_distance_km)]
road_graph = {
    "Home": [("Station", 2), ("Highway", 5)],
    "Station": [("Market", 6)],
    "Highway": [("Market", 2), ("Office", 7)],
    "Market": [("Office", 3)],
    "Office": []
}

# Straight-line heuristic distance to Office
heuristic = {
    "Home": 8,
    "Station": 7,
    "Highway": 4,
    "Market": 2,
    "Office": 0
}


def astar_search(start, goal):
    pq = [(heuristic[start], 0, start, [start])]
    visited = set()
    expanded = 0

    while pq:
        f, g, node, path = heapq.heappop(pq)
        if node in visited:
            continue
        visited.add(node)
        expanded += 1
        if node == goal:
            return path, g, expanded
        for nbr, cost in road_graph[node]:
            if nbr not in visited:
                new_g = g + cost
                heapq.heappush(pq, (new_g + heuristic[nbr], new_g, nbr, path + [nbr]))
    return None, 0, expanded


def greedy_best_first(start, goal):
    pq = [(heuristic[start], 0, start, [start])]
    visited = set()
    expanded = 0

    while pq:
        h, g, node, path = heapq.heappop(pq)
        if node in visited:
            continue
        visited.add(node)
        expanded += 1
        if node == goal:
            return path, g, expanded
        for nbr, cost in road_graph[node]:
            if nbr not in visited:
                heapq.heappush(pq, (heuristic[nbr], g + cost, nbr, path + [nbr]))
    return None, 0, expanded


a_path, a_cost, a_exp = astar_search("Home", "Office")
g_path, g_cost, g_exp = greedy_best_first("Home", "Office")

print("A* Search         -> Path:", a_path, "| Cost:", a_cost, "km | Nodes Expanded:", a_exp)
print("Greedy Best-First -> Path:", g_path, "| Cost:", g_cost, "km | Nodes Expanded:", g_exp)

"""
Output:
A* Search         -> Path: ['Home', 'Highway', 'Market', 'Office'] | Cost: 10 km | Nodes Expanded: 5
Greedy Best-First -> Path: ['Home', 'Highway', 'Office'] | Cost: 12 km | Nodes Expanded: 3
"""
