# 59. Write a Python program to implement a simple Markov chain model to predict the next state (e.g., weather prediction) from a transition matrix.
"""
Use: Used in weather forecasting, stock modeling, and text prediction where the next state depends only on the current state.
Process: A transition matrix stores probabilities of moving from Sunny, Cloudy, or Rainy to the next day's weather.
Given today's state vector, multiplying by the transition matrix predicts tomorrow's probability distribution.
Repeating this step forecasts the weather distribution 2 days ahead and identifies the most likely state.
"""

import numpy as np

states = ["Sunny", "Cloudy", "Rainy"]

# Transition matrix: rows = current state, cols = next state
transition_matrix = np.array([
    [0.7, 0.2, 0.1],  # From Sunny
    [0.3, 0.4, 0.3],  # From Cloudy
    [0.2, 0.3, 0.5]   # From Rainy
])

# Today is Sunny -> [1, 0, 0]
current_dist = np.array([1.0, 0.0, 0.0])

day1_dist = current_dist @ transition_matrix
day2_dist = day1_dist @ transition_matrix

print("Initial Weather Today: Sunny")
print("Day 1 Forecast:", {s: round(float(p), 3) for s, p in zip(states, day1_dist)})
print("Day 2 Forecast:", {s: round(float(p), 3) for s, p in zip(states, day2_dist)})
print("Most Likely Weather Tomorrow:", states[int(np.argmax(day1_dist))])

"""
Output:
Initial Weather Today: Sunny
Day 1 Forecast: {'Sunny': 0.7, 'Cloudy': 0.2, 'Rainy': 0.1}
Day 2 Forecast: {'Sunny': 0.57, 'Cloudy': 0.25, 'Rainy': 0.18}
Most Likely Weather Tomorrow: Sunny
"""
