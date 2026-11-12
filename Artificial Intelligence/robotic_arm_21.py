# 21. Create a Python class to simulate a robotic arm with position analysis.
"""
Use: Used in industrial robotics and manufacturing to calculate joint/gripper positions and workspace limits.
Process: Given link lengths (l1, l2) and joint angles (theta1, theta2), forward kinematics computes elbow and gripper coordinates.
Trigonometric projections (cos, sin) map the angles into 2D Cartesian (x, y) coordinates.
is_reachable() checks if a target point lies between |l1 - l2| and (l1 + l2).
"""

import math


# 2-Link Planar Robotic Arm class for factory assembly
class RoboticArm:

    def __init__(self, link1_len, link2_len):
        self.l1 = link1_len
        self.l2 = link2_len
        self.theta1 = 0.0
        self.theta2 = 0.0

    # Set joint angles (in degrees) and compute end-effector (x, y) position
    def move_to_angles(self, theta1_deg, theta2_deg):
        self.theta1 = theta1_deg
        self.theta2 = theta2_deg

        t1 = math.radians(theta1_deg)
        t2 = math.radians(theta2_deg)

        # Joint 1 (elbow) position
        x1 = self.l1 * math.cos(t1)
        y1 = self.l1 * math.sin(t1)

        # End-effector (gripper) position
        x2 = x1 + self.l2 * math.cos(t1 + t2)
        y2 = y1 + self.l2 * math.sin(t1 + t2)

        return (x1, y1), (x2, y2)

    # Check if a target point is within the arm's physical workspace
    def is_reachable(self, target_x, target_y):
        distance = math.hypot(target_x, target_y)
        min_reach = abs(self.l1 - self.l2)
        max_reach = self.l1 + self.l2
        return min_reach <= distance <= max_reach


# Real-life example: Car assembly robotic arm (links: 1.2 m and 0.8 m)
arm = RoboticArm(link1_len=1.2, link2_len=0.8)

elbow, gripper = arm.move_to_angles(45, 30)
print(f"Joint Angles: theta1={arm.theta1} deg, theta2={arm.theta2} deg")
print(f"Elbow Position: x={elbow[0]:.3f} m, y={elbow[1]:.3f} m")
print(f"Gripper Position: x={gripper[0]:.3f} m, y={gripper[1]:.3f} m")

# Check reachability of two conveyor belt parts
for label, (tx, ty) in [("Part A", (1.4, 0.9)), ("Part B", (2.5, 1.0))]:
    reachable = arm.is_reachable(tx, ty)
    print(f"Target {label} at ({tx}, {ty}) reachable? {reachable}")

"""
Output:
Joint Angles: theta1=45 deg, theta2=30 deg
Elbow Position: x=0.849 m, y=0.849 m
Gripper Position: x=1.056 m, y=1.621 m
Target Part A at (1.4, 0.9) reachable? True
Target Part B at (2.5, 1.0) reachable? False
"""
