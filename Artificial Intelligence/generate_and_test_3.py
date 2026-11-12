# 3. Demonstrate the generate-and-test method.
"""
Use: Used as a simple problem-solving method when candidate solutions can be easily listed and verified.
Process: The generator produces candidates one by one from a range of possible values.
Each candidate is passed to a test function to check if it satisfies the goal condition.
The search stops immediately and returns the first candidate that passes the test.
"""

def generate_and_test(candidates, test):
    for candidate in candidates:
        print(f"Testing candidate: {candidate}")
        if test(candidate):
            return candidate
    return None


if __name__ == "__main__":
    target = 25
    solution = generate_and_test(
        range(1, 11),
        lambda number: number * number == target,
    )

    if solution is None:
        print("No solution found.")
    else:
        print(f"Solution found: {solution} squared is {target}.")

"""
Output:
Testing candidate: 1
Testing candidate: 2
Testing candidate: 3
Testing candidate: 4
Testing candidate: 5
Solution found: 5 squared is 25.
"""
