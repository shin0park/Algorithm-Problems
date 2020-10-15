from copy import deepcopy

n, m = map(int, input().split())
init_board = [list(input()) for _ in range(n)]
red = []
blue = []
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
back_dir = [2, 3, 0, 1]
for i in range(n):
    for j in range(m):
        if init_board[i][j] == 'R':
            red = [i, j]
        elif init_board[i][j] == 'B':
            blue = [i, j]

marble = [red, blue]
result = 'fail'
min_value = int(1e9)

def moving(dir, board, temp_marble):
    if dir == 0:
        temp_marble.sort()
    elif dir == 1:
        temp_marble.sort(key=lambda x: x[1], reverse=True)
    elif dir == 2:
        temp_marble.sort(reverse=True)
    elif dir == 3:
        temp_marble.sort(key=lambda x: x[1])
    for i in range(2):
        x, y = temp_marble[i]
        color = board[x][y]
        board[x][y] = '.'
        while True:
            nx = x + dx[dir]
            ny = y + dy[dir]
            if nx <= 0 or nx >= n or ny <= 0 or ny >= m or board[nx][ny] != '.':
                break
            x, y = nx, ny
        if board[nx][ny] == 'O':
            continue
        temp_marble[i] = [x, y]
        if color == 'R':
            board[x][y] = 'R'
        else:
            board[x][y] = 'B'


def is_finish(board):
    global result
    is_red = False
    is_blue = False
    for i in range(1, n - 1):
        for j in range(1, m - 1):
            if board[i][j] == 'R':
                is_red = True
            elif board[i][j] == 'B':
                is_blue = True
    if is_red and is_blue:
        return False
    elif is_red:
        result = 'fail'
        return True
    elif is_blue:
        result = 'success'
        return True
    else:
        result = 'fail'
        return True


def able(dir, board, marble):
    for i in range(2):
        x, y = marble[i]
        nx, ny = x + dx[dir], y + dy[dir]
        if board[nx][ny] == '.' or board[nx][ny] == 'O':
            return True
    return False


def dfs(cnt, board, pre, marble):
    global min_value
    temp = deepcopy(board)
    temp_marble = deepcopy(marble)
    if cnt > 10 or is_finish(temp):
        if result != 'fail':
            min_value = min(min_value, cnt)
        return
    for i in range(4):
        if cnt > 0 and (i == pre or i == back_dir[pre]):
            continue
        if not able(i, temp, temp_marble):
            continue
        moving(i, temp, temp_marble)
        dfs(cnt + 1, temp, i, temp_marble)
        temp = deepcopy(board)
        temp_marble = deepcopy(marble)

dfs(0, init_board, 1, marble)
if min_value > 10:
    print(-1)
else:
    print(min_value)
