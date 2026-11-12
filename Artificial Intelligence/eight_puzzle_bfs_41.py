# 41. Write a Python program to implement breadth-first search (BFS) to solve the 8-puzzle problem.
"""
Use: Used in state-space search and sliding-puzzle AI to guarantee the shortest sequence of moves to the goal.
Process: Starting from the initial 3x3 board tuple, BFS uses a FIFO queue to explore all states level by level.
For each state, the blank tile (0) is swapped with valid neighbors (Up, Down, Left, Right).
Visited states are tracked in a set until the goal configuration is reached.
"""

from collections import deque


def bfs_8_puzzle(start, goal):
    queue = deque([(start, [start])])
    visited = {start}

    while queue:
        state, path = queue.popleft()
        if state == goal:
            return path

        zero = state.index(0)
        row, col = divmod(zero, 3)

        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nr, nc = row + dr, col + dc
            if 0 <= nr < 3 and 0 <= nc < 3:
                swap_idx = nr * 3 + nc
                new_list = list(state)
                new_list[zero], new_list[swap_idx] = new_list[swap_idx], new_list[zero]
                new_state = tuple(new_list)
                if new_state not in visited:
                    visited.add(new_state)
                    queue.append((new_state, path + [new_state]))

    return None


start_board = (1, 2, 3, 4, 0, 5, 7, 8, 6)
goal_board = (1, 2, 3, 4, 5, 6, 7, 8, 0)

solution_path = bfs_8_puzzle(start_board, goal_board)
print(f"Solved in {len(solution_path) - 1} moves:")
for step, board in enumerate(solution_path):
    print(f"Step {step}: {board[0:3]} / {board[3:6]} / {board[6:9]}")

"""
Output:
Solved in 2 moves:
Step 0: (1, 2, 3) / (4, 0, 5) / (7, 8, 6)
Step 1: (1, 2, 3) / (4, 5, 0) / (7, 8, 6)
Step 2: (1, 2, 3) / (4, 5, 6) / (7, 8, 0)
"""
