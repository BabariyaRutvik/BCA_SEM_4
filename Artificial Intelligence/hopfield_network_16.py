# 16. Implement a Python class for a Hopfield network and simulate its behavior on a simple input.
"""
Use: Used as an associative memory neural network to recover clean stored patterns from noisy or corrupted inputs.
Process: During training, the weight matrix stores bipolar (+1, -1) patterns using Hebbian outer products.
During recall, each neuron updates its state based on the weighted sum of other neurons' states.
This repeats until the network settles into the closest stored pattern.
"""

# Hopfield Network class for associative memory
class HopfieldNetwork:

    def __init__(self, size):
        self.size = size
        self.weights = [[0] * size for _ in range(size)]

    # Train weights using Hebbian learning on stored bipolar patterns (+1, -1)
    def train(self, patterns):
        for pattern in patterns:
            for i in range(self.size):
                for j in range(self.size):
                    if i != j:
                        self.weights[i][j] += pattern[i] * pattern[j]

    # Recall a stored pattern from a noisy/corrupted input
    def recall(self, input_pattern, max_iterations=10):
        state = list(input_pattern)

        for _ in range(max_iterations):
            updated = False
            for i in range(self.size):
                activation = sum(self.weights[i][j] * state[j] for j in range(self.size))
                new_val = 1 if activation >= 0 else -1
                if new_val != state[i]:
                    state[i] = new_val
                    updated = True
            if not updated:
                break

        return state


# Real-life example: Recovering a corrupted 4-bit smart-card access code
stored_codes = [
    [1, -1, 1, -1],   # Admin access pattern
    [-1, 1, -1, 1]    # Guest access pattern
]

network = HopfieldNetwork(size=4)
network.train(stored_codes)

# Corrupted signal read by card scanner (3rd bit flipped due to noise)
corrupted_code = [1, -1, -1, -1]
recovered_code = network.recall(corrupted_code)

print("Stored Access Patterns:", stored_codes)
print("Corrupted Scanner Input:", corrupted_code)
print("Recovered Access Pattern:", recovered_code)

"""
Output:
Stored Access Patterns: [[1, -1, 1, -1], [-1, 1, -1, 1]]
Corrupted Scanner Input: [1, -1, -1, -1]
Recovered Access Pattern: [1, -1, 1, -1]
"""
