'''
스타트 택시
'''
from collections import deque
n, m, fuel = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
people = [[0] * n for _ in range(n)]
startX, startY = map(int, input().split())
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]
startX -= 1
startY -= 1
dest = [[0,0]]
for i in range(m):
    psx, psy, pdx, pdy = map(int, input().split())
    people[psx - 1][psy - 1] = i + 1
    dest.append([pdx - 1, pdy - 1])

def find_people(sx, sy):
    result = []
    dist = [[-1]*n for _ in range(n)]
    q = deque([])
    q.append([sx, sy])
    dist[sx][sy] = 0
    result_dist = 0
    while q:
        x, y = q.popleft()
        if people[x][y] != 0:
            result_dist = dist[x][y]
            result.append([x, y, people[x][y], result_dist])
            break
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if dist[nx][ny] != -1 or board[nx][ny] == 1: #방문 or 벽
                continue
            dist[nx][ny] = dist[x][y] + 1
            q.append([nx,ny])
    while q:
        x, y = q.popleft()
        if people[x][y] != 0 and dist[x][y] == result_dist:
            result.append([x, y, people[x][y], dist[x][y]])
    result.sort()
    if not result:
        return [0,0,0,0]
    else:
        return result[0]
def moving(sx, sy, dest_spot):
    global fuel
    dist = [[-1] * n for _ in range(n)]
    q = deque([])
    q.append([sx, sy])
    dist[sx][sy] = 0
    while q:
        x, y = q.popleft()
        if fuel >= dist[x][y] and [x,y] == dest_spot:
            fuel += dist[x][y]
            return True
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            # 벽이거나 방문
            if dist[nx][ny] != -1 or board[nx][ny] == 1:
                continue
            dist[nx][ny] = dist[x][y] + 1
            q.append([nx,ny])
    return False

while m:
    rideX, rideY, people_num, moving_len = find_people(startX, startY)
    fuel -= moving_len
    if fuel < 0 or people_num == 0:
        break
    people[rideX][rideY] = 0
    moving_result = moving(rideX, rideY, dest[people_num])
    startX, startY = dest[people_num]
    if not moving_result:
        break
    m -= 1
if m != 0:
    print(-1)
else:
    print(fuel)