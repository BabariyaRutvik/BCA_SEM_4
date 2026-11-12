# 12. Write a Python program that simulates backward reasoning for a simple expert system.
"""
Use: Used in goal-driven expert systems to verify whether a specific hypothesis or goal is true.
Process: Starting from a target goal, backward_reasoning() checks if it is already a known fact.
If not, it looks up rules that conclude the goal and recursively tries to prove all required conditions.
The goal is proven once every supporting condition resolves back to known facts.
"""

# Known facts in the expert system
facts = {"has_fur", "barks"}

# Rules mapping conclusion -> list of required conditions
rules = {
    "is_mammal": [["has_fur"]],
    "is_dog": [["is_mammal", "barks"]],
    "is_cat": [["is_mammal", "meows"]]
}


# Recursive backward reasoning function
def backward_reasoning(goal):
    print("Checking goal:", goal)

    # Base case: goal is already a known fact
    if goal in facts:
        print(goal, "is a known fact.")
        return True

    # Check if there are rules that can prove the goal
    if goal in rules:
        for conditions in rules[goal]:
            if all(backward_reasoning(cond) for cond in conditions):
                print("Proven:", goal)
                return True

    print("Cannot prove:", goal)
    return False


# Test backward reasoning with a target goal
target_goal = "is_dog"
print("Target Goal:", target_goal)
result = backward_reasoning(target_goal)

print("\nGoal Proven:" if result else "\nGoal Not Proven:", target_goal)

"""
Output:
Target Goal: is_dog
Checking goal: is_dog
Checking goal: is_mammal
Checking goal: has_fur
has_fur is a known fact.
Proven: is_mammal
Checking goal: barks
barks is a known fact.
Proven: is_dog

Goal Proven: is_dog
"""
