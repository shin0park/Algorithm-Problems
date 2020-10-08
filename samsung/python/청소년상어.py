import copy
dx = [0,-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 0, -1, -1, -1, 0, 1, 1, 1]
board = []
fish_max = 16
for i in range(4):
    arr = list(map(int, input().split()))
    temp = []
    for j in range(4):
        temp.append([arr[j*2], arr[j*2+1]])
    board.append(temp)
answer = 0
max_value = 0
def find_dish(board, index):
    for i in range(4):
        for j in range(4):
            if board[i][j][0] == index:
                return [i,j]
    return None

def dfs(board, start, answer):
    global max_value
    board = copy.deepcopy(board)
    sx, sy = start
    fish_num, shark_dir = board[sx][sy]
    answer += fish_num
    max_value = max(max_value, answer)
    #shark
    board[sx][sy] = [0, 0]
    for i in range(1, 17):
        position = find_dish(board, i)
        if position == None:
            continue
        x, y = position
        dir = board[x][y][1]
        is_move = False
        for j in range(8):
            nx, ny = x + dx[dir], y + dy[dir]
            #경계 넘거나 상어 있을전 경우 회
            if nx < 0 or nx >= 4 or ny < 0 or ny >= 4 or [nx, ny] == [sx, sy]:
                dir += 1
                if dir > 8:
                    dir = 1
                board[x][y][1] = dir
                continue
            else:
                is_move = True
                break
        if is_move:
            #자리 교체
            board[x][y], board[nx][ny] = board[nx][ny], board[x][y]

    is_vaild = False
    while True:
        nx, ny = sx + dx[shark_dir], sy + dy[shark_dir]
        if nx < 0 or nx >= 4 or ny < 0 or ny >= 4:
            break
        if board[nx][ny][0] != 0:
            is_vaild = True
            dfs(board, [nx, ny], answer)
        sx, sy = nx, ny
    if not is_vaild:
        return

dfs(board, [0, 0], 0)
print(max_value)


