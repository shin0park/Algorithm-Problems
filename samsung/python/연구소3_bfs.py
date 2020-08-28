from itertools import combinations
from collections import deque
import sys

dx = [-1,0,0,1]
dy = [0,-1,1,0]
board = []
answer = int(1e9)
virus_spot= []
empty_cnt = 0
is_vaild = False

def bfs(virus, n):
    cnt = 0
    time = 0
    dist = [[-1] * n for _ in range(n)]
    q = deque(virus)
    for i, j in virus:
        dist[i][j] = 0
    while q:
        x, y = q.popleft()
        for dir in range(4):
            nx = x + dx[dir]
            ny = y + dy[dir]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if dist[nx][ny] != -1 or board[nx][ny] == 1 :
                continue
            dist[nx][ny] = dist[x][y] + 1
            if board[nx][ny] != 2:
                time = dist[nx][ny]
                cnt += 1
            q.append([nx, ny])
    if cnt != empty_cnt:
        return -1
    return time

#입력
n, m = map(int, input().split())
for i in range(n):
    board.append(list(map(int, sys.stdin.readline().split())))
    for j in range(n):
        if board[i][j] == 2:
            virus_spot.append([i,j])
        elif board[i][j] == 0:
            empty_cnt += 1
#조합구하기
virus_com = list(map(list,combinations(virus_spot, m)))

for com in virus_com:
    result = bfs(com,n)
    if result != -1:
        is_vaild = True
        answer = min(answer, result)

if is_vaild:
    print(answer)
else:
    print(-1)

