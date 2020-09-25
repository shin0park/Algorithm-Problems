from collections import deque
INF = int(1e9)
n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
start = []
shark_size = 2
time = 0
for i in range(n):
    for j in range(n):
        if board[i][j] == 9:
            start = [i, j]
            board[i][j] = 0
dx = [-1,0,0,1]
dy = [0,-1,1,0]
def bfs():
    dist = [[-1] * n for _ in range(n)]
    q = deque([])
    sx, sy = start
    q.append([sx, sy])
    dist[sx][sy] = 0
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if dist[nx][ny] != -1 or board[nx][ny] > shark_size:
                continue
            dist[nx][ny] = dist[x][y] + 1
            q.append([nx, ny])
    return dist

def find(dist):
    min_dist = INF
    stop = []
    for i in range(n):
        for j in range(n):
            if dist[i][j] != -1 and board[i][j] != 0 and board[i][j] < shark_size:
                if dist[i][j] < min_dist:
                    min_dist = dist[i][j]
                    stop = [i, j]
    return stop, min_dist
ate = 0
while True:
    start, min_dist = find(bfs())
    if min_dist != INF:
        i, j = start
        board[i][j] = 0
        ate += 1
        if shark_size == ate:
            shark_size += 1
            ate = 0
        time += min_dist
    else:
        break
print(time)