# 4. Write Python code to simulate hill climbing search for a given cost function.
"""
Use: Used in optimization problems to find the minimum or maximum of a cost function efficiently.
Process: Starting from an initial position, the algorithm evaluates immediate neighbors (x - 1, x + 1).
If a neighbor has a lower cost, it moves to that neighbor and repeats the process.
It stops when no neighbor improves the current cost, reaching a local minimum.
"""

def cost_function(x):
    return (x - 3) ** 2 + 2

# hill climbing algorithm
def hill_climbing(start):
    current = start
    while True:
        neighbors = [current - 1, current + 1]
        next_node = min(neighbors, key=cost_function)

        if cost_function(next_node) >= cost_function(current):
            break

        current = next_node

        print("Current Position:", current, "Cost:", cost_function(current))

    return current


if __name__ == "__main__":
    result = hill_climbing(0)
    print("Local Minimum:", result)

"""
Output:
Current Position: 1 Cost: 6
Current Position: 2 Cost: 3
Current Position: 3 Cost: 2
Local Minimum: 3
"""