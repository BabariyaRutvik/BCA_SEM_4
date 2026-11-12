# 23. Develop a Python program to create a basic robot programming language and run simple commands.
"""
Use: Used in automated warehouses and robotics to script high-level robot tasks using human-readable commands.
Process: The RobotInterpreter class parses each text instruction (MOVE, PICK, DROP, STATUS) line by line.
It dispatches each command to update the robot's coordinates and carried item state.
This separates task scripting from low-level robot execution logic.
"""

# Interpreter for a simple Warehouse Robot Command Language
class RobotInterpreter:

    def __init__(self):
        self.x = 0
        self.y = 0
        self.holding = None

    def execute(self, script):
        for line in script:
            parts = line.strip().split()
            cmd = parts[0].upper()

            if cmd == "MOVE":
                dx, dy = int(parts[1]), int(parts[2])
                self.x += dx
                self.y += dy
                print(f"Moved by ({dx}, {dy}) -> Position: ({self.x}, {self.y})")

            elif cmd == "PICK":
                item = parts[1]
                self.holding = item
                print(f"Picked up item: {self.holding}")

            elif cmd == "DROP":
                print(f"Dropped item: {self.holding} at ({self.x}, {self.y})")
                self.holding = None

            elif cmd == "STATUS":
                print(f"Status -> Position: ({self.x}, {self.y}), Holding: {self.holding}")

            else:
                print(f"Unknown command: {line}")


# Real-life example: Automated warehouse pick-and-deliver script
robot_program = [
    "MOVE 3 2",
    "PICK Laptop_Box",
    "MOVE 4 -1",
    "DROP",
    "STATUS"
]

print("Executing Robot Program:")
bot = RobotInterpreter()
bot.execute(robot_program)

"""
Output:
Executing Robot Program:
Moved by (3, 2) -> Position: (3, 2)
Picked up item: Laptop_Box
Moved by (4, -1) -> Position: (7, 1)
Dropped item: Laptop_Box at (7, 1)
Status -> Position: (7, 1), Holding: None
"""
