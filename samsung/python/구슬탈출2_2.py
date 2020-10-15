'''
bfs로 풀기
'''
from collections import deque

n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]
dist = [[[[-1] * m for _ in range(n)] for _ in range(m)] for _ in range(n)]
red_x, red_y, blue_x, blue_y = 0, 0, 0, 0
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
min_value = 11
for i in range(n):
    for j in range(m):
        if board[i][j] == 'R':
            red_x, red_y = i, j
            board[i][j] = '.'
        elif board[i][j] == 'B':
            blue_x, blue_y = i, j
            board[i][j] = '.'


def moving(x, y, dir):
    cnt = 0
    while True:
        nx, ny = x + dx[dir], y + dy[dir]
        if board[nx][ny] == '#' or board[x][y] == 'O':
            break
        cnt += 1
        x, y = nx, ny
    return x, y, cnt


def bfs(srx, sry, sbx, sby):
    global min_value
    q = deque()
    q.append([srx, sry, sbx, sby])
    dist[srx][sry][sbx][sby] = 0
    while q:
        rx, ry, bx, by = q.popleft()
        if dist[rx][ry][bx][by] > 10:
            return
        for i in range(4):
            next_rx, next_ry, r_move_len = moving(rx, ry, i)
            next_bx, next_by, b_move_len = moving(bx, by, i)
            if board[next_bx][next_by] == 'O':
                continue
            if board[next_rx][next_ry] == 'O':
                min_value = dist[rx][ry][bx][by] + 1
                return
            if next_rx == next_bx and next_ry == next_by:
                if r_move_len > b_move_len:  # 이동 거리가 많은 구슬을 한칸 뒤로
                    next_rx -= dx[i]
                    next_ry -= dy[i]
                else:
                    next_bx -= dx[i]
                    next_by -= dy[i]
            if dist[next_rx][next_ry][next_bx][next_by] == -1:
                dist[next_rx][next_ry][next_bx][next_by] = dist[rx][ry][bx][by] + 1
                q.append([next_rx, next_ry, next_bx, next_by])


bfs(red_x, red_y, blue_x, blue_y)

if min_value > 10:
    print(-1)
else:
    print(min_value)
