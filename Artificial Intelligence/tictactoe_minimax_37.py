# 37. Implement an AI agent that plays Tic-Tac-Toe against a human using the Minimax algorithm.
"""
Use: Used in two-player turn-based games (like Tic-Tac-Toe or Chess) to make an AI play optimally.
Process: Minimax recursively explores all possible future moves assuming the AI ('O') maximizes score
and the human ('X') minimizes score. Terminal wins return +1 or -1, and draws return 0.
The AI selects the move with the highest Minimax value at each turn.
"""


def print_board(board):
    for i in range(0, 9, 3):
        print(" | ".join(board[i:i + 3]))
    print()


def check_winner(board):
    win_lines = [
        (0, 1, 2), (3, 4, 5), (6, 7, 8),
        (0, 3, 6), (1, 4, 7), (2, 5, 8),
        (0, 4, 8), (2, 4, 6)
    ]
    for a, b, c in win_lines:
        if board[a] == board[b] == board[c] != " ":
            return board[a]
    return "Draw" if " " not in board else None


def minimax(board, is_maximizing):
    winner = check_winner(board)
    if winner == "O":
        return 1
    if winner == "X":
        return -1
    if winner == "Draw":
        return 0

    if is_maximizing:
        best_score = -100
        for i in range(9):
            if board[i] == " ":
                board[i] = "O"
                best_score = max(best_score, minimax(board, False))
                board[i] = " "
        return best_score
    else:
        best_score = 100
        for i in range(9):
            if board[i] == " ":
                board[i] = "X"
                best_score = min(best_score, minimax(board, True))
                board[i] = " "
        return best_score


def best_ai_move(board):
    best_score = -100
    move = -1
    for i in range(9):
        if board[i] == " ":
            board[i] = "O"
            score = minimax(board, False)
            board[i] = " "
            if score > best_score:
                best_score = score
                move = i
    return move


# Simulate a game against human moves: X plays at 0, then 8, then 6
board = [" "] * 9
human_moves = [0, 8, 6, 3]

for h_move in human_moves:
    if board[h_move] == " " and check_winner(board) is None:
        board[h_move] = "X"
        print(f"Human (X) plays position {h_move}:")
        print_board(board)

    if check_winner(board) is None:
        ai_move = best_ai_move(board)
        board[ai_move] = "O"
        print(f"AI (O) plays position {ai_move}:")
        print_board(board)

    result = check_winner(board)
    if result is not None:
        print("Game Result:", "Draw!" if result == "Draw" else f"{result} wins!")
        break

"""
Output:
Human (X) plays position 0:
X |   |  
  |   |  
  |   |  

AI (O) plays position 4:
X |   |  
  | O |  
  |   |  

Human (X) plays position 8:
X |   |  
  | O |  
  |   | X

AI (O) plays position 1:
X | O |  
  | O |  
  |   | X

Human (X) plays position 6:
X | O |  
  | O |  
X |   | X

AI (O) plays position 7:
X | O |  
  | O |  
X | O | X

Game Result: O wins!
"""
