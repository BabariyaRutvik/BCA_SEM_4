# 47. Write a Python program to implement steepest-ascent hill climbing and compare it with simple hill climbing on the same problem.
"""
Use: Used to compare two local search variants on how quickly and effectively they climb toward an optimum.
Process: Simple hill climbing moves to the first neighbor that improves the score f(x).
Steepest-ascent hill climbing evaluates all neighbors (step sizes -2, -1, +1, +2) and picks the best one.
Comparing both from the same start shows steps taken and the final peak reached.
"""


# Objective function to maximize: f(x) = -(x - 7)^2 + 50
def objective(x):
    return -((x - 7) ** 2) + 50


def simple_hill_climbing(start):
    current = start
    steps = 0
    while True:
        moved = False
        for delta in [-1, 1, -2, 2]:
            nxt = current + delta
            if objective(nxt) > objective(current):
                current = nxt
                steps += 1
                moved = True
                break
        if not moved:
            break
    return current, objective(current), steps


def steepest_ascent_hill_climbing(start):
    current = start
    steps = 0
    while True:
        neighbors = [current + d for d in [-1, 1, -2, 2]]
        best_nbr = max(neighbors, key=objective)
        if objective(best_nbr) <= objective(current):
            break
        current = best_nbr
        steps += 1
    return current, objective(current), steps


s_x, s_val, s_steps = simple_hill_climbing(0)
sa_x, sa_val, sa_steps = steepest_ascent_hill_climbing(0)

print("Function: f(x) = -(x - 7)^2 + 50 | Start: x = 0")
print(f"Simple Hill Climbing          -> x = {s_x}, f(x) = {s_val}, Steps = {s_steps}")
print(f"Steepest-Ascent Hill Climbing -> x = {sa_x}, f(x) = {sa_val}, Steps = {sa_steps}")

"""
Output:
Function: f(x) = -(x - 7)^2 + 50 | Start: x = 0
Simple Hill Climbing          -> x = 7, f(x) = 50, Steps = 7
Steepest-Ascent Hill Climbing -> x = 7, f(x) = 50, Steps = 4
"""
