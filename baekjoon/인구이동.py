'''
인구이동으로 인구가 변하는 지점을 2차원 배열에 체크하여 값을 변경해주니
시간초과가 떴다.
이럴경우 list 에 변하는 지점을 append하여 그 지점만 접근해서
값을 수정해주는게 더 효율적이다.
'''
from _collections import deque
import sys
input = sys.stdin.readline
n, l, r = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
visited = [[0] * n for _ in range(n)]
answer = 0
def bfs(start):
    dx = [-1,0,1,0]
    dy = [0,1,0,-1]
    united = []
    q = deque([])
    x, y = start
    q.append(start)
    united.append(start)
    visited[x][y] = 1
    sum_value = board[x][y]
    cnt = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if visited[nx][ny] != 0:
                continue
            gap = abs(board[x][y] - board[nx][ny])
            if gap < l or gap > r:
                continue
            visited[nx][ny] = 1
            sum_value += board[nx][ny]
            cnt += 1
            united.append([nx, ny])
            q.append([nx, ny])
    if cnt == 1:
        return False
    else:
        value = sum_value // cnt
        for i, j in united:
            board[i][j] = value
        return True

while True:
    is_vaild = False
    visited = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if visited[i][j] == 0:
                result = bfs([i,j])
                if result:
                    is_vaild = True
    if not is_vaild:
        break
    answer += 1
print(answer)