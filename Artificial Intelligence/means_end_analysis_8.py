# 8. Implement Means-End analysis for a simple problem using Python.
"""
Use: Used in AI planning to step-by-step reduce the difference between the current state and the goal state.
Process: The algorithm compares current_state with goal_state to detect what is missing or different.
It then selects an action/operator that reduces that difference and updates the current state.
This cycle repeats until the current state matches the goal state.
"""
# Define current and goal states
current_state = "Home"
goal_state = "Office"

print("Current State:", current_state)
print("Goal State:", goal_state)

# Define actions
actions = {
    "Home": "Travel to Office",
    "Office": "Goal Reached"
}

# Means-End Analysis
while current_state != goal_state:

    # Find the difference
    print("\nDifference: Not at", goal_state)

    # Select an action
    action = actions[current_state]
    print("Action:", action)

    # Apply the action
    if current_state == "Home":
        current_state = "Office"

print("\nFinal State:", current_state)
print("Goal Achieved Successfully!")

"""
Output:
Current State: Home
Goal State: Office

Difference: Not at Office
Action: Travel to Office

Final State: Office
Goal Achieved Successfully!
"""
