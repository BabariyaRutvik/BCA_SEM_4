# 45. Write a Python program to implement simulated annealing to minimize a given function.
"""
Use: Used in global optimization (scheduling, VLSI layout, tuning) to escape local minima.
Process: Starting from an initial x and high temperature T, the algorithm proposes a random neighbor.
Better solutions are always accepted, while worse solutions are accepted with probability exp(-delta / T).
As temperature cools down, the search narrows and settles near the global minimum.
"""

import math
import random

random.seed(42)


# Cost function to minimize: f(x) = (x - 4)^2 + 5
def objective(x):
    return (x - 4.0) ** 2 + 5.0


def simulated_annealing(start_x, temp=100.0, cooling_rate=0.95, steps=120):
    current_x = start_x
    current_cost = objective(current_x)
    best_x, best_cost = current_x, current_cost

    for _ in range(steps):
        candidate_x = current_x + random.uniform(-1.0, 1.0)
        candidate_cost = objective(candidate_x)
        delta = candidate_cost - current_cost

        if delta < 0 or random.random() < math.exp(-delta / temp):
            current_x, current_cost = candidate_x, candidate_cost
            if current_cost < best_cost:
                best_x, best_cost = current_x, current_cost

        temp *= cooling_rate

    return best_x, best_cost


best_x, min_val = simulated_annealing(start_x=-10.0)
print("Function: f(x) = (x - 4)^2 + 5")
print("Start Position: x = -10.0, f(x) =", objective(-10.0))
print(f"Found Minimum: x = {best_x:.4f}, f(x) = {min_val:.4f}")

"""
Output:
Function: f(x) = (x - 4)^2 + 5
Start Position: x = -10.0, f(x) = 201.0
Found Minimum: x = 3.9047, f(x) = 5.0091
"""
