n, l = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
answer = 0


def rotate(board):
    new_board = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            new_board[j][i] = board[i][j]
    return new_board


def check_able_route(board):
    global answer
    # 행
    for i in range(n):
        is_vaild_right = True
        cnt = 1
        # 오른쪽 방향
        check = [0] * n
        pre = board[i][0]
        for j in range(1, n):
            if pre == board[i][j]:
                cnt += 1
                continue
            elif pre < board[i][j]:
                if pre == board[i][j] - 1 and cnt >= l:
                    for k in range(1, l + 1):
                        if check[j - k] == 0:
                            check[j - k] = 1
                        else:
                            is_vaild_right = False
                    cnt = 1
                    pre = board[i][j]
                    continue
                else:
                    is_vaild_right = False
                    break
            else:
                cnt = 1
                pre = board[i][j]
        if not is_vaild_right:
            continue
        is_vaild_left = True
        cnt = 1
        # 왼쪽 방향
        pre = board[i][-1]
        for j in range(n - 2, -1, -1):
            if pre == board[i][j]:
                cnt += 1
                continue
            elif pre < board[i][j]:
                if pre == board[i][j] - 1 and cnt >= l:
                    for k in range(1, l + 1):
                        if check[j + k] == 0:
                            check[j + k] = 1
                        else:
                            is_vaild_left = False
                    cnt = 1
                    pre = board[i][j]
                    continue
                else:
                    is_vaild_left = False
                    break
            else:
                cnt = 1
                pre = board[i][j]
        if is_vaild_left:
            answer += 1


check_able_route(board)
check_able_route(rotate(board))
print(answer)
