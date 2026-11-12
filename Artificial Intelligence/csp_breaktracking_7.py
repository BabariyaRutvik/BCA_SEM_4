
# Program 7: CSP Using Backtracking
"""
Use: Used in scheduling, timetabling, and resource allocation where variables must satisfy constraints.
Process: Variables are assigned values from their domains one at a time.
Before each assignment, is_valid() verifies that no constraint (such as duplicate slot usage) is violated.
If a dead end occurs, the algorithm backtracks, removes the assignment, and tries the next value.
"""

# Define variables and their domains
variables = ['A', 'B', 'C']

domains = {
    'A': ['Morning', 'Afternoon', 'Evening'],
    'B': ['Morning', 'Afternoon', 'Evening'],
    'C': ['Morning', 'Afternoon', 'Evening']
}

# Store assigned values
assignment = {}

# Check constraints
def is_valid(variable, value):

    for assigned_value in assignment.values():

        if assigned_value == value:
            return False

    return True


# Backtracking function
def backtracking(index):

    # Check if all variables are assigned
    if index == len(variables):
        return True

    variable = variables[index]

    # Try all possible values
    for value in domains[variable]:

        if is_valid(variable, value):

            assignment[variable] = value

            # Solve the next variable
            if backtracking(index + 1):
                return True

            # Backtrack if no solution is found
            del assignment[variable]

    return False


# Start solving the problem
if backtracking(0):

    print("Solution Found:")

    for variable, value in assignment.items():
        print(variable, "=", value)

else:
    print("No Solution Found")

"""
Output:
Solution Found:
A = Morning
B = Afternoon
C = Evening
"""
