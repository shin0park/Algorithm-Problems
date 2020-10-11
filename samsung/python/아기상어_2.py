from collections import deque

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
shark_x, shark_y = 0, 0
shark_size = 2
eating_cnt = 0
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

for i in range(N):
    for j in range(N):
        if board[i][j] == 9:
            shark_x, shark_y = i, j
            board[i][j] = 0


def find_fish(sx, sy):
    global shark_size, eating_cnt
    dist = [[-1] * N for _ in range(N)]
    q = deque()
    q.append([sx, sy])
    dist[sx][sy] = 0
    result = []
    is_find = False
    while q:
        x, y = q.popleft()
        if board[x][y] != 0 and board[x][y] < shark_size:
            result.append([dist[x][y], x, y])
            is_find = True
            continue
        if is_find:
            continue
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            # 이미 방문했거나 상어크기보다 큰 물고기가 있을 때
            if dist[nx][ny] != -1 or board[nx][ny] > shark_size:
                continue
            dist[nx][ny] = dist[x][y] + 1
            q.append([nx, ny])
    result.sort()
    print(result)
    if result:
        return result[0]
    else:
        return False


answer = 0
while True:
    eating = find_fish(shark_x, shark_y)
    if not eating:
        break
    time, shark_x, shark_y = eating
    board[shark_x][shark_y] = 0
    eating_cnt += 1
    if eating_cnt == shark_size:
        shark_size += 1
        eating_cnt = 0
    answer += time

print(answer)
