# 28. Implement a Python program to demonstrate the frame problem in AI.
"""
Use: Demonstrates a classic AI challenge: ensuring actions only change relevant states while unrelated facts stay intact.
Process: A smart home world state tracks robot/package locations alongside door lock, light, and thermostat values.
When move_package() executes, it copies the existing state (frame axiom) and updates only location keys.
All unrelated properties remain unchanged without needing separate rules for every unaffected fact.
"""

# Initial world state of a smart home delivery robot
world_state = {
    "robot_location": "Kitchen",
    "package_location": "Kitchen",
    "front_door_locked": True,
    "living_room_light": "OFF",
    "thermostat_c": 24
}


# Action: Move robot with package to another room
# Frame axioms ensure unrelated properties remain unchanged
def move_package(state, destination):
    new_state = state.copy()  # Frame axiom: copy unchanged fluents automatically
    new_state["robot_location"] = destination
    new_state["package_location"] = destination
    return new_state


print("Initial Smart Home State:")
for k, v in world_state.items():
    print(f"- {k}: {v}")

# Robot delivers medicine package from Kitchen to Bedroom
updated_state = move_package(world_state, "Bedroom")

print("\nState After Robot Moves Package to Bedroom:")
for k, v in updated_state.items():
    print(f"- {k}: {v}")

"""
Output:
Initial Smart Home State:
- robot_location: Kitchen
- package_location: Kitchen
- front_door_locked: True
- living_room_light: OFF
- thermostat_c: 24

State After Robot Moves Package to Bedroom:
- robot_location: Bedroom
- package_location: Bedroom
- front_door_locked: True
- living_room_light: OFF
- thermostat_c: 24
"""
