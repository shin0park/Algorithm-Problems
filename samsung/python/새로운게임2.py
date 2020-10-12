n, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
horse = [[0, 0, 0]]
horse_state = [[None] * n for _ in range(n)]
dx = [0, 0, 0, -1, 1]
dy = [0, 1, -1, 0, 0]
for i in range(n):
    for j in range(n):
        horse_state[i][j] = []
for i in range(k):
    x, y, d = map(int, input().split())
    horse.append([x - 1, y - 1, d])
    horse_state[x - 1][y - 1].append(i + 1)


def back_dir(dir):
    if dir == 1 or dir == 2:
        return 3 - dir
    elif dir == 3 or dir == 4:
        return 7 - dir


def moving(num, x, y, dir):
    # 파란색
    nx, ny = x + dx[dir], y + dy[dir]
    if nx < 0 or nx >= n or ny < 0 or ny >= n or board[nx][ny] == 2:
        dir = back_dir(dir)
        nx, ny = x + dx[dir], y + dy[dir]
        horse[num][2] = dir
        if nx < 0 or nx >= n or ny < 0 or ny >= n or board[nx][ny] == 2:
            return False
    lst = horse_state[x][y]
    h_index = lst.index(num)
    moving_lst = lst[h_index:]
    # 삭제
    horse_state[x][y] = lst[:h_index]
    # 흰색
    if board[nx][ny] == 0:
        horse_state[nx][ny] += moving_lst
    # 빨간색
    elif board[nx][ny] == 1:
        horse_state[nx][ny] += moving_lst[::-1]
    for h in moving_lst:
        horse[h][0], horse[h][1] = nx, ny
    # 말 4개 이상 쌓이면 게임 종료
    if len(horse_state[nx][ny]) >= 4:
        return True
    return False


time = 0
while time <= 1000:
    time += 1
    is_end = False
    # 말 이동
    for num in range(1, k + 1):
        x, y, dir = horse[num]
        result = moving(num, x, y, dir)
        if result:
            is_end = True
            break
    # 게임 종료
    if is_end:
        break

if time <= 1000:
    print(time)
else:
    print(-1)
