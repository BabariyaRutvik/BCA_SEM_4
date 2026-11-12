# 43. Write a Python program to solve the N-Queens problem and display all valid board configurations.
"""
Use: Used in constraint satisfaction and scheduling to place non-conflicting items on an NxN grid.
Process: Backtracking places one queen per row and checks column and diagonal safety against prior rows.
If a position is safe, it recurses to the next row; otherwise, it backtracks to try another column.
Every complete placement of N queens is saved and printed as a valid board configuration.
"""


def solve_n_queens(n):
    solutions = []
    board = [-1] * n  # board[row] = column

    def is_safe(row, col):
        for r in range(row):
            if board[r] == col or abs(board[r] - col) == abs(r - row):
                return False
        return True

    def backtrack(row):
        if row == n:
            solutions.append(list(board))
            return
        for col in range(n):
            if is_safe(row, col):
                board[row] = col
                backtrack(row + 1)

    backtrack(0)
    return solutions


n = 4
all_solutions = solve_n_queens(n)
print(f"Total Valid Configurations for {n}-Queens: {len(all_solutions)}")

for idx, sol in enumerate(all_solutions, start=1):
    print(f"\nConfiguration {idx}:")
    for col in sol:
        row_str = ["Q" if c == col else "." for c in range(n)]
        print(" ".join(row_str))

"""
Output:
Total Valid Configurations for 4-Queens: 2

Configuration 1:
. Q . .
. . . Q
Q . . .
. . Q .

Configuration 2:
. . Q .
Q . . .
. . . Q
. Q . .
"""
