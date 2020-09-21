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
    time = 0
    q = deque([])
    for num, vx, vy in virus:
        q.append([vx,vy])
    
    if s == 0:
        print(board[x-1][y-1])
        return
    
    while q and s != 0:
        new_q = copy.deepcopy(q)
        time += 1
        while new_q:
            px, py = new_q.popleft()
            q.popleft()
            for i in range(4):
                nx, ny = px + dx[i], py + dy[i]
                if nx < 0 or nx >= n or ny <= 0 or ny >= n:
                    continue
                if board[nx][ny] != 0:
                    continue
                board[nx][ny] = board[px][py]
                q.append([nx,ny])
        if time == s:
            break    
    print(board[x-1][y-1])
    return

bfs(board)
