from collections import deque
from itertools import combinations
N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
empty_list = []
virus = []
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
wall_cnt = 0

def my_combinations(arr, r):
    for i in range(len(arr)):
        if r == 1:
            yield [arr[i]]
        else:
            for next in my_combinations(arr[i + 1:], r - 1):
                yield [arr[i]] + next


def bfs():
    result = 0
    visited = [[0] * M for _ in range(N)]
    q = deque()
    for x, y in virus:
        q.append([x, y])
        visited[x][y] = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if visited[nx][ny] == 1 or board[nx][ny] == 1:
                continue
            visited[nx][ny] = 1
            q.append([nx, ny])
    for i in range(N):
        for j in range(M):
            if visited[i][j] == 0:
                result += 1
    result -= wall_cnt
    return result


for i in range(N):
    for j in range(M):
        if board[i][j] == 0:
            empty_list.append([i, j])
        elif board[i][j] == 2:
            virus.append([i, j])
        else:
            wall_cnt += 1
wall_cnt += 3
max_value = 0
for com in combinations(empty_list, 3):
    # 벽 세우기
    for x, y in com:
        board[x][y] = 1
    max_value = max(max_value, bfs())
    for x, y in com:
        board[x][y] = 0
print(max_value)
