from itertools import combinations
from collections import deque
n,m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
wall_able = []
virus = []
k = 3
max_value = 0

def bfs(virus):
    cnt = 0
    dx = [-1,0,1,0]
    dy = [0,-1,0,1]
    visited = [[0] * m for _ in range(n)]
    q = deque([])
    for vx, vy in virus:
        q.append([vx,vy])
        visited[vx][vy] = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if board[nx][ny] != 0 or visited[nx][ny] != 0:
                continue
            visited[nx][ny] = 1
            cnt += 1
            q.append([nx,ny])
    return cnt
            
for i in range(n):
    for j in range(m):
        if board[i][j] == 0:
            wall_able.append((i, j))
        elif board[i][j] == 2:
            virus.append((i,j))
            
empty_cnt = len(wall_able)

for com in combinations(wall_able, k):
    for r,c in com:
        board[r][c] = 1
    result = bfs(virus)
    result = empty_cnt - (result + k)
    max_value = max(max_value, result)
    for r,c in com:
        board[r][c] = 0
        
print(max_value)
    
