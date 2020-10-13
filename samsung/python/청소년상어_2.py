import copy

fish_board = []
shark_x, shark_y, shark_dir = 0, 0, 0
dx = [0, -1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 0, -1, -1, -1, 0, 1, 1, 1]
fish = [[] for _ in range(17)]
for i in range(4):
    arr = list(map(int, input().split()))
    temp = []
    for j in range(4):
        temp.append([arr[j * 2], arr[j * 2 + 1]])
    fish_board.append(temp)
answer = 0


# 17번 상어 0은 빈칸
def rotate(dir):
    if dir == 8:
        return 1
    else:
        return dir + 1


def moving(board):
    for num in range(1, 17):
        is_fish = False
        for i in range(4):
            for j in range(4):
                if board[i][j][0] == num:
                    is_fish = True
                    x, y, dir = i, j, board[i][j][1]
        if not is_fish:
            continue
        is_change = False
        for _ in range(8):
            nx, ny = x + dx[dir], y + dy[dir]
            # 경계넘거나 상어 있을 때 방향 바꾼다.
            if nx < 0 or nx >= 4 or ny < 0 or ny >= 4 or board[nx][ny][0] == 17:
                dir = rotate(dir)
                continue
            is_change = True
            break
        if not is_change:
            continue
        board[x][y][1] = dir
        board[x][y], board[nx][ny] = board[nx][ny], board[x][y]
    return board


def dfs(sx, sy, board, total_sum):
    global answer
    board = copy.deepcopy(board)
    dir = board[sx][sy][1]
    total_sum += board[sx][sy][0]
    board[sx][sy] = [17, dir]
    board = moving(board)
    x, y = sx, sy
    board[x][y] = [0, 0]
    for i in range(1, 4):
        nx, ny = x + dx[dir] * i, y + dy[dir] * i
        # 경계 넘어가거나 빈칸 일때
        if nx < 0 or nx >= 4 or ny < 0 or ny >= 4:
            break
        if board[nx][ny][0] == 0:
            continue
        dfs(nx, ny, board, total_sum)
    answer = max(answer, total_sum)
    return


dfs(0, 0, fish_board, 0)
print(answer)
