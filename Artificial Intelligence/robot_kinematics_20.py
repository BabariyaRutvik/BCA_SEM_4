# 20. Write a Python script to simulate the basic working of a robot's kinematics.
"""
Use: Used in mobile robotics to track a robot's 2D position and heading from movement and steering commands.
Process: Starting from origin (0, 0) at 0 degrees, each command updates the robot's heading angle theta.
Forward kinematics uses cos(theta) and sin(theta) to compute the new (x, y) displacement.
Successive steps trace the robot's path from the charging dock to the packing bay.
"""

import math


# Simulate 2D forward kinematics of a warehouse delivery robot
def simulate_robot_kinematics(commands):
    x, y, theta_deg = 0.0, 0.0, 0.0  # Start at origin facing East (0 deg)
    print(f"Start Position -> x: {x:.2f} m, y: {y:.2f} m, heading: {theta_deg:.1f} deg")

    for step, (distance, turn_deg) in enumerate(commands, start=1):
        theta_deg = (theta_deg + turn_deg) % 360
        theta_rad = math.radians(theta_deg)

        # Update robot coordinates using forward kinematics
        x += distance * math.cos(theta_rad)
        y += distance * math.sin(theta_rad)

        print(
            f"Step {step}: Turn {turn_deg:+} deg, Move {distance} m -> "
            f"x: {x:.2f} m, y: {y:.2f} m, heading: {theta_deg:.1f} deg"
        )

    return x, y, theta_deg


# Real-life example: Warehouse robot navigating from Charging Dock to Packing Bay
path_commands = [
    (4.0, 0),    # Move 4m East along main aisle
    (3.0, 90),   # Turn 90 deg North and move 3m
    (2.0, -45)   # Turn -45 deg (Northeast) and move 2m to Packing Bay
]

final_x, final_y, final_heading = simulate_robot_kinematics(path_commands)
print(f"\nFinal Robot Pose: x={final_x:.2f} m, y={final_y:.2f} m, heading={final_heading:.1f} deg")

"""
Output:
Start Position -> x: 0.00 m, y: 0.00 m, heading: 0.0 deg
Step 1: Turn +0 deg, Move 4.0 m -> x: 4.00 m, y: 0.00 m, heading: 0.0 deg
Step 2: Turn +90 deg, Move 3.0 m -> x: 4.00 m, y: 3.00 m, heading: 90.0 deg
Step 3: Turn -45 deg, Move 2.0 m -> x: 5.41 m, y: 4.41 m, heading: 45.0 deg

Final Robot Pose: x=5.41 m, y=4.41 m, heading=45.0 deg
"""
