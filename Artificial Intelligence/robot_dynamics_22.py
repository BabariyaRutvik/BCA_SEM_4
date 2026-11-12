# 22. Write a Python program to implement dynamic analysis of a robot's movement.
"""
Use: Used in robotics engineering to analyze how forces, payload weight, and friction affect robot motion.
Process: Total mass combines robot mass and payload mass, from which floor friction is calculated.
Net force (motor force minus friction) is divided by total mass to get acceleration (F = m * a).
Over discrete time steps dt, velocity and position are updated iteratively.
"""

# Simulate linear dynamics of an autonomous delivery robot carrying a payload
def simulate_robot_dynamics(robot_mass, payload_mass, motor_force, friction_coeff, dt, steps):
    total_mass = robot_mass + payload_mass
    gravity = 9.81
    friction_force = friction_coeff * total_mass * gravity

    velocity = 0.0
    position = 0.0

    print(f"Total Mass: {total_mass} kg | Motor Force: {motor_force} N | Friction: {friction_force:.2f} N")
    print("\nTime(s) | Acceleration(m/s^2) | Velocity(m/s) | Position(m)")

    for step in range(1, steps + 1):
        net_force = max(0.0, motor_force - friction_force)
        acceleration = net_force / total_mass
        velocity += acceleration * dt
        position += velocity * dt
        time_s = step * dt

        print(f"{time_s:6.1f}  | {acceleration:19.3f} | {velocity:13.3f} | {position:11.3f}")


# Real-life example: 25 kg warehouse robot carrying a 15 kg package
simulate_robot_dynamics(
    robot_mass=25.0,
    payload_mass=15.0,
    motor_force=80.0,
    friction_coeff=0.08,
    dt=1.0,
    steps=5
)

"""
Output:
Total Mass: 40.0 kg | Motor Force: 80.0 N | Friction: 31.39 N

Time(s) | Acceleration(m/s^2) | Velocity(m/s) | Position(m)
   1.0  |               1.215 |         1.215 |       1.215
   2.0  |               1.215 |         2.430 |       3.646
   3.0  |               1.215 |         3.646 |       7.291
   4.0  |               1.215 |         4.861 |      12.152
   5.0  |               1.215 |         6.076 |      18.228
"""
