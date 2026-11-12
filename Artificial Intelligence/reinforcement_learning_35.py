# 35. Implement a Python program that applies reinforcement learning to train a simple robotic agent.
"""
Use: Used in robotics to teach an agent optimal navigation through trial-and-error rewards without hardcoding paths.
Process: A 1D warehouse corridor (states 0..4) has a hazard at state 2 (-5 reward) and a charging dock at state 4 (+10 reward).
Using Q-learning, the robot explores actions (Left/Right) and updates Q-values via the Bellman equation.
After training episodes, the learned policy guides the robot from state 0 to the charging dock.
"""

import random

random.seed(42)

# States: 0 (Start) -> 1 -> 2 (Obstacle: -5) -> 3 -> 4 (Charging Dock: +10)
num_states = 5
actions = [-1, 1]  # -1: Left, +1: Right
q_table = [[0.0, 0.0] for _ in range(num_states)]

rewards = [-0.1, -0.1, -5.0, -0.1, 10.0]
alpha = 0.2    # Learning rate
gamma = 0.9    # Discount factor
epsilon = 0.2  # Exploration rate

# Train using Q-learning
for _ in range(200):
    state = 0
    while state != 4:
        if random.random() < epsilon:
            action_idx = random.choice([0, 1])
        else:
            action_idx = 0 if q_table[state][0] >= q_table[state][1] else 1

        next_state = max(0, min(num_states - 1, state + actions[action_idx]))
        reward = rewards[next_state]

        best_next = max(q_table[next_state])
        q_table[state][action_idx] += alpha * (reward + gamma * best_next - q_table[state][action_idx])
        state = next_state

print("Learned Q-Table (Left, Right):")
for s in range(num_states):
    print(f"State {s}: Left={q_table[s][0]:.2f}, Right={q_table[s][1]:.2f}")

# Follow learned optimal policy from Start (0) to Dock (4)
path = [0]
curr = 0
while curr != 4 and len(path) < 10:
    best_act = 0 if q_table[curr][0] >= q_table[curr][1] else 1
    curr = max(0, min(num_states - 1, curr + actions[best_act]))
    path.append(curr)

print("\nOptimal Path to Charging Dock:", path)

"""
Output:
Learned Q-Table (Left, Right):
State 0: Left=2.22, Right=2.61
State 1: Left=2.13, Right=3.01
State 2: Left=2.58, Right=8.90
State 3: Left=2.99, Right=10.00
State 4: Left=0.00, Right=0.00

Optimal Path to Charging Dock: [0, 1, 2, 3, 4]
"""
