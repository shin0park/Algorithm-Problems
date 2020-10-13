'''
이전 풀이 방식에서 했던
list 에 변하는 지점을 append하여 그 지점만 접근해서
값을 수정해주는게 더 효율적이다.
'''
from collections import deque

n, l, r = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
turn = 0
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def bfs(sx, sy, united_num):
    q = deque()
    q.append([sx, sy])
    united[sx][sy] = united_num
    cnt = 1
    sum = board[sx][sy]
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= n or united[nx][ny] != 0:
                continue
            gap = abs(board[x][y] - board[nx][ny])
            if l <= gap <= r:
                q.append([nx, ny])
                united[nx][ny] = united_num
                cnt += 1
                sum += board[nx][ny]

    value = sum // cnt
    if cnt == 1:
        new_board[sx][sy] = value
        return False
    for i in range(n):
        for j in range(n):
            if united[i][j] == united_num:
                new_board[i][j] = value
    return True


while True:
    new_board = [[0] * n for _ in range(n)]
    united = [[0] * n for _ in range(n)]
    united_num = 1
    is_end = True
    for i in range(n):
        for j in range(n):
            if united[i][j] == 0:
                result = bfs(i, j, united_num)
                if result:
                    is_end = False
                united_num += 1
    board = new_board
    if is_end:
        break
    turn += 1
print(turn)
