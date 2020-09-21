'''
#첫번쨰 풀이에서 한 time에 퍼지는 바이러스를 q에 저장하고
다시 새로운 q를 생성하는 방식이 아닌
하나의 큐에 하되 q에 dist처럼 time을 같이 append해준다.
pop했을때 s와 같을경우 break해준다.
'''
from collections import deque
import copy
dx = [-1,0,1,0]
dy = [0,-1,0,1]
n, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
s, x, y = map(int, input().split())
virus = []
    
for i in range(n):
    for j in range(n):
        if board[i][j] != 0:
            num = board[i][j]
            virus.append((num, i, j))
virus.sort()
#bfs
def bfs(board):
    q = deque([])
    for num, vx, vy in virus:
        q.append((0,vx,vy))
    
    if s == 0:
        print(board[x-1][y-1])
        return
    
    while q:
        ps, px, py = q.popleft()
        if ps == s:
            break
        for i in range(4):
            nx, ny = px + dx[i], py + dy[i]
            if nx < 0 or nx >= n or ny <= 0 or ny >= n:
                continue
            if board[nx][ny] != 0:
                continue
            board[nx][ny] = board[px][py]
            q.append((ps+1,nx,ny))   
    print(board[x-1][y-1])
    return

bfs(board)
