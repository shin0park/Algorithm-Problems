n, m = map(int, input().split())
r, c, d = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def turn_left(direction):
    if direction == 0:
        return 3
    else:
        return direction - 1


answer = 0
is_vaild = True
while is_vaild:
    for i in range(4):
        if board[r][c] == 0:  # 빈칸의 경우 청소한다.
            board[r][c] = 2
            answer += 1
        d = turn_left(d)
        nx = r + dx[d]
        ny = c + dy[d]
        if board[nx][ny] == 0:
            r, c = nx, ny
            break
        # 후진 1은 3으로 0은 2로 방향이 바뀌므로 -값을 취하면 된다.
        if i == 3:
            nx = r - dx[d]
            ny = c - dy[d]
            if board[nx][ny] != 1:  # 뒤에 벽이 없을 경우 후진
                r, c = nx, ny
            else:  # 종료
                is_vaild = False

print(answer)
