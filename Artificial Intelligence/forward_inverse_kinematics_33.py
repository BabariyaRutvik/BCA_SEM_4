# 33. Develop a Python script to simulate robot kinematics and calculate forward and inverse kinematics.
"""
Use: Used in robotic arms to convert joint angles to gripper coordinates (forward) and target coordinates to angles (inverse).
Process: forward_kinematics() projects link lengths L1 and L2 using cos and sin of joint angles (theta1, theta2).
inverse_kinematics() uses the law of cosines and atan2 to solve for the joint angles needed to reach (x, y).
Running both confirms the calculated angles return the exact target position.
"""

import math


# Forward Kinematics: (theta1, theta2) -> (x, y)
def forward_kinematics(l1, l2, theta1_deg, theta2_deg):
    t1 = math.radians(theta1_deg)
    t2 = math.radians(theta2_deg)
    x = l1 * math.cos(t1) + l2 * math.cos(t1 + t2)
    y = l1 * math.sin(t1) + l2 * math.sin(t1 + t2)
    return x, y


# Inverse Kinematics: (x, y) -> (theta1, theta2) using Law of Cosines
def inverse_kinematics(l1, l2, target_x, target_y):
    dist_sq = target_x ** 2 + target_y ** 2
    cos_t2 = (dist_sq - l1 ** 2 - l2 ** 2) / (2 * l1 * l2)
    cos_t2 = max(-1.0, min(1.0, cos_t2))  # Clamp for numerical safety

    t2 = math.acos(cos_t2)
    k1 = l1 + l2 * math.cos(t2)
    k2 = l2 * math.sin(t2)
    t1 = math.atan2(target_y, target_x) - math.atan2(k2, k1)

    return math.degrees(t1), math.degrees(t2)


# Real-life example: Pick-and-place assembly arm (L1 = 1.0 m, L2 = 0.8 m)
L1, L2 = 1.0, 0.8
target = (1.2, 0.9)

theta1, theta2 = inverse_kinematics(L1, L2, target[0], target[1])
check_x, check_y = forward_kinematics(L1, L2, theta1, theta2)

print(f"Target Gripper Position: x={target[0]:.3f} m, y={target[1]:.3f} m")
print(f"Inverse Kinematics Angles: theta1={theta1:.2f} deg, theta2={theta2:.2f} deg")
print(f"Forward Kinematics Verification: x={check_x:.3f} m, y={check_y:.3f} m")

"""
Output:
Target Gripper Position: x=1.200 m, y=0.900 m
Inverse Kinematics Angles: theta1=7.33 deg, theta2=67.59 deg
Forward Kinematics Verification: x=1.200 m, y=0.900 m
"""
