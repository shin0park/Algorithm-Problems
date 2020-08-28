def solution(board):
    answer = 1
    width = len(board[0])
    height = len(board)
    for i in range(1, height):
        for j in range(1, width):
            if board[i][j] == 1:
                board[i][j] = min(board[i-1][j-1], min(board[i-1][j], board[i][j-1])) + 1
                answer = max(answer, board[i][j])
    return answer ** 2
