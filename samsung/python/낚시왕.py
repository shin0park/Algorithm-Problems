R, C, M = map(int, input().split())
board = [[0] * C for _ in range(R)]
sharks = {}
answer = 0
dx = [0, -1, 1, 0, 0]
dy = [0, 0, 0, 1, -1]

# 제일 가까운 상어 잡아먹는다
def catching_shark(c):
    global answer
    for i in range(R):
        if board[i][c] != 0:
            answer += board[i][c]
            board[i][c] = 0
            break
#방향 전환
def turn(dir):
    if dir == 1 or dir == 2:
        return 3 - dir
    elif dir == 3 or dir == 4:
        return 7 - dir
#상어 이동
def moving(sx, sy, shark_size, shark_s, dir):
    x, y = sx, sy
    for i in range(shark_s):
        nx, ny = x + dx[dir], y + dy[dir]
        if nx < 0 or nx >= R or ny < 0 or ny >= C:
            dir = turn(dir)
            nx, ny = x + dx[dir], y + dy[dir]
        x, y = nx, ny
    return x, y, dir

for i in range(M):
    r, c, s, d, z = map(int, input().split())
    board[r - 1][c - 1] = z
    sharks[z] = [s, d]

for col in range(C):
    #상어를 잡아먹는다
    catching_shark(col)
    new_board = [[0] * C for _ in range(R)]
    for i in range(R):
        for j in range(C):
            if board[i][j] == 0:
                continue
            shark_size = board[i][j]
            shark_s, shark_d = sharks[shark_size]
            #움직인 좌표
            nx, ny, new_dir = moving(i, j, shark_size, shark_s, shark_d)
            #바뀐 방향 업데이트
            sharks[shark_size][1] = new_dir
            #움직인 칸에 더 큰 상어가 있을 경우
            if new_board[nx][ny] != 0:
                new_board[nx][ny] = max(new_board[nx][ny], shark_size)
            else:
                new_board[nx][ny] = shark_size
    board = new_board
print(answer)