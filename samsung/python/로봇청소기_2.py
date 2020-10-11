n, m = map(int, input().split())
r, c, dir = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
answer = 0
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

x, y = r, c
while True:
    is_able = False
    # 청소
    if board[x][y] == 0:
        board[x][y] = 2
        answer += 1

    for i in range(4):
        dir = (dir - 1) % 4
        nx, ny = x + dx[dir], y + dy[dir]
        # 이미 청소했거나 벽인 경우
        if board[nx][ny] != 0:
            continue
        x, y = nx, ny
        is_able = True
        break

    if not is_able:
        nx, ny = x - dx[dir], y - dy[dir]
        if board[nx][ny] == 1:
            break
        x, y = nx, ny
print(answer)
