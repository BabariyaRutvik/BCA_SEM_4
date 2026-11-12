# 30. Write a Python program that simulates means-ends analysis in a robotic planning system.
"""
Use: Used in robotic task planning to generate a valid sequence of actions that transforms an initial state into a goal.
Process: Each robot operator defines preconditions, add-effects, and delete-effects.
While the goal state is not yet reached, the planner selects an applicable operator whose effects advance the state.
Applying operators in sequence updates the state until all goal conditions are satisfied.
"""

# Means-Ends Analysis for a Warehouse Parcel Delivery Robot
current_state = {"at_dock", "shelf_b_blocked", "parcel_unloaded"}
goal_state = {"at_shelf_b", "parcel_placed"}

# Operators: (name, preconditions, add_effects, delete_effects)
operators = [
    ("PICK_PARCEL", {"at_dock", "parcel_unloaded"}, {"holding_parcel"}, {"parcel_unloaded"}),
    ("MOVE_TO_SHELF_B", {"at_dock", "holding_parcel"}, {"at_shelf_b"}, {"at_dock"}),
    ("CLEAR_SHELF_B", {"at_shelf_b", "shelf_b_blocked"}, {"shelf_b_clear"}, {"shelf_b_blocked"}),
    ("PLACE_PARCEL", {"at_shelf_b", "holding_parcel", "shelf_b_clear"}, {"parcel_placed"}, {"holding_parcel"})
]

print("Initial Robot State:", sorted(current_state))
print("Goal State:", sorted(goal_state))
print("\nPlanning Steps:")

plan = []
while not goal_state.issubset(current_state):
    applied = False
    for name, preconds, add_eff, del_eff in operators:
        if preconds.issubset(current_state) and not add_eff.issubset(current_state):
            print(f"Execute Operator: {name}")
            current_state = (current_state - del_eff) | add_eff
            plan.append(name)
            applied = True
            break
    if not applied:
        print("Planning failed: no applicable operator.")
        break

print("\nFinal Robot State:", sorted(current_state))
print("Generated Plan:", plan)

"""
Output:
Initial Robot State: ['at_dock', 'parcel_unloaded', 'shelf_b_blocked']
Goal State: ['at_shelf_b', 'parcel_placed']

Planning Steps:
Execute Operator: PICK_PARCEL
Execute Operator: MOVE_TO_SHELF_B
Execute Operator: CLEAR_SHELF_B
Execute Operator: PLACE_PARCEL

Final Robot State: ['at_shelf_b', 'parcel_placed', 'shelf_b_clear']
Generated Plan: ['PICK_PARCEL', 'MOVE_TO_SHELF_B', 'CLEAR_SHELF_B', 'PLACE_PARCEL']
"""
