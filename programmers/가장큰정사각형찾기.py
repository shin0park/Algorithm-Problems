def solution(board):
    width = len(board[0])
    height = len(board)
    for i in range(1, height):
        for j in range(1, width):
            if board[i][j] == 1:
                board[i][j] = min(board[i-1][j-1], min(board[i-1][j], board[i][j-1])) + 1
    return max([item for row in board for item in row]) ** 2
