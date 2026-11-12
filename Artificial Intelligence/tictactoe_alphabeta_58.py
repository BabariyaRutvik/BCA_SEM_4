# 58. Write a Python program to implement the Minimax algorithm with alpha-beta pruning for Tic-Tac-Toe and compare the nodes visited.
"""
Use: Used in game-playing AI (Chess, Checkers, Tic-Tac-Toe) to speed up Minimax without changing the optimal move.
Process: Standard Minimax explores every branch of the game tree from a partially filled board.
Alpha-beta pruning tracks bounds (alpha for maximizer, beta for minimizer) and cuts off branches
that cannot affect the final decision, dramatically reducing the number of nodes visited.
"""


def check_winner(board):
    lines = [(0, 1, 2), (3, 4, 5), (6, 7, 8), (0, 3, 6), (1, 4, 7), (2, 5, 8), (0, 4, 8), (2, 4, 6)]
    for a, b, c in lines:
        if board[a] == board[b] == board[c] != " ":
            return board[a]
    return "Draw" if " " not in board else None


def minimax(board, is_max, counter):
    counter[0] += 1
    winner = check_winner(board)
    if winner == "O":
        return 1
    if winner == "X":
        return -1
    if winner == "Draw":
        return 0

    best = -100 if is_max else 100
    for i in range(9):
        if board[i] == " ":
            board[i] = "O" if is_max else "X"
            val = minimax(board, not is_max, counter)
            board[i] = " "
            best = max(best, val) if is_max else min(best, val)
    return best


def alphabeta(board, is_max, alpha, beta, counter):
    counter[0] += 1
    winner = check_winner(board)
    if winner == "O":
        return 1
    if winner == "X":
        return -1
    if winner == "Draw":
        return 0

    if is_max:
        best = -100
        for i in range(9):
            if board[i] == " ":
                board[i] = "O"
                best = max(best, alphabeta(board, False, alpha, beta, counter))
                board[i] = " "
                alpha = max(alpha, best)
                if beta <= alpha:
                    break
        return best
    else:
        best = 100
        for i in range(9):
            if board[i] == " ":
                board[i] = "X"
                best = min(best, alphabeta(board, True, alpha, beta, counter))
                board[i] = " "
                beta = min(beta, best)
                if beta <= alpha:
                    break
        return best


# Sample mid-game board (O's turn)
sample_board = ["X", " ", " ", " ", "O", " ", " ", " ", "X"]

mm_nodes = [0]
ab_nodes = [0]

mm_score = minimax(list(sample_board), True, mm_nodes)
ab_score = alphabeta(list(sample_board), True, -100, 100, ab_nodes)

print("Sample Board:", sample_board)
print(f"Standard Minimax   -> Best Score: {mm_score}, Nodes Visited: {mm_nodes[0]}")
print(f"Alpha-Beta Pruning -> Best Score: {ab_score}, Nodes Visited: {ab_nodes[0]}")
print(f"Nodes Saved by Pruning: {mm_nodes[0] - ab_nodes[0]}")

"""
Output:
Sample Board: ['X', ' ', ' ', ' ', 'O', ' ', ' ', ' ', 'X']
Standard Minimax   -> Best Score: 0, Nodes Visited: 1053
Alpha-Beta Pruning -> Best Score: 0, Nodes Visited: 318
Nodes Saved by Pruning: 735
"""
