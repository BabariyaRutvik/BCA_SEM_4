# 42. Write a Python program to solve the Water Jug problem using DFS and display the sequence of states.
"""
Use: Used in state-space problem solving to measure an exact target volume using two ungraduated jugs.
Process: DFS explores valid operations (fill jug, empty jug, pour from one jug to the other) from (0, 0).
A visited set prevents infinite loops among repeated states.
When either jug reaches the target volume (2 liters), the sequence of states is returned.
"""


def water_jug_dfs(cap1, cap2, target):
    visited = set()
    path = []

    def dfs(j1, j2):
        if (j1, j2) in visited:
            return False
        visited.add((j1, j2))
        path.append((j1, j2))

        if j1 == target or j2 == target:
            return True

        next_states = [
            (cap1, j2),  # Fill Jug 1
            (j1, cap2),  # Fill Jug 2
            (0, j2),     # Empty Jug 1
            (j1, 0),     # Empty Jug 2
            (j1 - min(j1, cap2 - j2), j2 + min(j1, cap2 - j2)),  # Pour 1 -> 2
            (j1 + min(j2, cap1 - j1), j2 - min(j2, cap1 - j1))   # Pour 2 -> 1
        ]

        for nj1, nj2 in next_states:
            if dfs(nj1, nj2):
                return True

        path.pop()
        return False

    dfs(0, 0)
    return path


states = water_jug_dfs(4, 3, 2)
print("Water Jug (4L, 3L -> Target 2L) DFS Solution States:")
for step, state in enumerate(states):
    print(f"Step {step}: Jug1 = {state[0]}L, Jug2 = {state[1]}L")

"""
Output:
Water Jug (4L, 3L -> Target 2L) DFS Solution States:
Step 0: Jug1 = 0L, Jug2 = 0L
Step 1: Jug1 = 4L, Jug2 = 0L
Step 2: Jug1 = 4L, Jug2 = 3L
Step 3: Jug1 = 0L, Jug2 = 3L
Step 4: Jug1 = 3L, Jug2 = 0L
Step 5: Jug1 = 3L, Jug2 = 3L
Step 6: Jug1 = 4L, Jug2 = 2L
"""
