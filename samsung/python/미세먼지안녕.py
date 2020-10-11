R, C, T = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(R)]
air_x, air_y = 0, 0
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
for i in range(R):
    for j in range(C):
        if board[i][j] == -1:
            air_x, air_y = i, j
air_x -= 1


# 미세먼지 확산
def spread():
    new_board = [[0] * C for _ in range(R)]
    for i in range(R):
        for j in range(C):
            if board[i][j] == 0:
                continue
            if board[i][j] == -1:
                new_board[i][j] = -1
            else:
                center = board[i][j]
                spread_value = center // 5
                x, y = i, j
                cnt = 0
                for k in range(4):
                    nx, ny = x + dx[k], y + dy[k]
                    # 공기청정기가 있거나 벽일 경우
                    if nx < 0 or nx >= R or ny < 0 or ny >= C or board[nx][ny] == -1:
                        continue
                    new_board[nx][ny] += spread_value
                    cnt += 1
                center -= spread_value * cnt
                new_board[i][j] += center
    return new_board


def air_run():
    # 위 반시계 방향
    x, y = air_x, air_y
    for r in range(x - 1, 0, -1):
        board[r][0] = board[r - 1][0]
    for c in range(0, C - 1):
        board[0][c] = board[0][c + 1]
    for r in range(0, x):
        board[r][C - 1] = board[r + 1][C - 1]
    for c in range(C - 1, 1, -1):
        board[x][c] = board[x][c - 1]
    board[x][1] = 0
    # 아래 시계방향
    x, y = air_x + 1, air_y
    for r in range(x + 1, R - 1):
        board[r][0] = board[r + 1][0]
    for c in range(0, C - 1):
        board[R - 1][c] = board[R - 1][c + 1]
    for r in range(R - 1, x, -1):
        board[r][C - 1] = board[r - 1][C - 1]
    for c in range(C - 1, 1, -1):
        board[x][c] = board[x][c - 1]
    board[x][1] = 0


for t in range(T):
    board = spread()
    air_run()

answer = 0
for i in range(R):
    for j in range(C):
        if board[i][j] == 0 or board[i][j] == -1:
            continue
        answer += board[i][j]
print(answer)
