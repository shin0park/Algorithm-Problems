from collections import deque
from itertools import combinations
N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
empty_num = 0
virus = []
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

#itertools 사용 안될 경우
def my_combinations(arr, r):
    for i in range(len(arr)):
        if r == 1:
            yield [arr[i]]
        else:
            for next in my_combinations(arr[i + 1:], r - 1):
                yield [arr[i]] + next


def spread(act_virus, empty_num):
    dist = [[-1] * N for _ in range(N)]
    q = deque()
    for v in act_virus:
        q.append(v)
        dist[v[0]][v[1]] = 0
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            # 경계를 넘거나 벽또는 이미 방문한 경우
            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            if dist[nx][ny] != -1 or board[nx][ny] == 1:
                continue
            dist[nx][ny] = dist[x][y] + 1
            q.append((nx, ny))
            if board[nx][ny] != 2:
                empty_num -= 1
                if empty_num == 0:
                    return dist[nx][ny]
    return -1


is_vaild = False
min_time = int(1e9)

for i in range(N):
    for j in range(N):
        if board[i][j] == 0:
            empty_num += 1
        elif board[i][j] == 2:
            virus.append((i, j))
for com in combinations(virus, M):
    time = spread(com, empty_num)
    if time != -1:
        is_vaild = True
        min_time = min(min_time, time)

if empty_num == 0:
    print(0)
elif is_vaild:
    print(min_time)
else:
    print(-1)
