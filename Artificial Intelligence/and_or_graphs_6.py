
# 6. Write a Python script to implement problem reduction and search using AND-OR graphs.
"""
Use: Used to break complex problems into smaller subproblems with mandatory (AND) or alternative (OR) parts.
Process: The recursive solver starts at the root problem and inspects each node's relation.
For AND nodes, all child subproblems must be solved; for OR nodes, solving any one child suffices.
Leaf nodes with no subproblems are directly marked as solved.
"""

# Define the AND-OR graph
graph = {
    'Complete Project': [
        ('AND', ['Design', 'Implementation'])
    ],
    'Implementation': [
        ('OR', ['Python', 'Java'])
    ],
    'Design': [],
    'Python': [],
    'Java': []
}

# Function to solve the problem
def solve(node):

    print("Solving:", node)

    # If node has no subproblems, it is solved
    if node not in graph or not graph[node]:
        print(node, "is solved")
        return True

    # Check the available relationships
    for relation, children in graph[node]:

        if relation == 'AND':

            # All children must be solved
            for child in children:
                if not solve(child):
                    return False

            return True

        elif relation == 'OR':

            # Any one child must be solved
            for child in children:
                if solve(child):
                    return True

            return False


# Start problem reduction
result = solve('Complete Project')

if result:
    print("\nProject Completed Successfully!")
else:
    print("\nProject Cannot Be Completed!")

"""
Output:
Solving: Complete Project
Solving: Design
Design is solved
Solving: Implementation
Solving: Python
Python is solved

Project Completed Successfully!
"""
