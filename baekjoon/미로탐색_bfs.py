from collections import deque

n, m = map(int, input().split())
board = [list(map(int, input())) for _ in range(n)]
dist = [[-1] * m for _ in range(n)]
x, y = 0, 0
dx = [-1,0,0,1]
dy = [0,-1,1,0]

q = deque([])
q.append([x, y])
dist[x][y] = 1
while q:
  x, y = q.popleft()
  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]
    if nx < 0 or nx >= n or ny < 0 or ny >= m:
      continue
    if board[nx][ny] and dist[nx][ny] == -1:
      dist[nx][ny] = dist[x][y] + 1
      q.append([nx,ny])

print(dist[n-1][m-1])

  

