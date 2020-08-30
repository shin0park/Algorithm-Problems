import sys
#계속 런타임 에러가 났던 이유
# 파이썬의 재귀깊이제한때문 - python3의 경우 제한을 바꿀수 있다.
sys.setrecursionlimit(10**6)

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
area = 0
answer = 0
max_area = 0

def dfs(x, y):
  global area
  if x < 0 or x >= n or y < 0 or y >= m:
    return False
  if board[x][y] == 1:#그림
    board[x][y] = 0
    area += 1

    dfs(x - 1, y)
    dfs(x, y - 1)
    dfs(x + 1, y)
    dfs(x, y + 1)
    return True
  return False

for i in range(n):
  for j in range(m):
    if dfs(i, j) == True:
      answer += 1
      max_area = max(max_area, area)
      area = 0
      
print(answer)
print(max_area)
