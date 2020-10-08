n, m, k = map(int, input().split())
sharks = [list(map(int, input().split())) for _ in range(n)]
board = [[[0,0] for _ in range(n)] for _ in range(n)]
dir = [0]
dir += list(map(int, input().split()))
priorites = []
dx = [0,-1,1,0,0]
dy = [0,0,0,-1,1]

for _ in range(m):
    #1,2,3,4 위 아래 왼 오
    dict = {}
    for i in range(1, 5):
        dict[i] = list(map(int, input().split()))
    priorites.append(dict)

time = 0
alive_sharks = m
def smell():
    for i in range(n):
        for j in range(n):
            #상어
            if sharks[i][j] != 0:
                num = sharks[i][j]
                board[i][j] = [num, k]

def update_smell():
    for i in range(n):
        for j in range(n):
            if board[i][j] != [0,0]:
                if board[i][j][1] == 1:
                    board[i][j] = [0,0]
                else:
                    board[i][j][1] -= 1

while time <= 1000:
    if alive_sharks == 1:
        break
    update_smell()
    smell()
    next_sharks = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            #상어
            if sharks[i][j] != 0:
                num = sharks[i][j]
                dir_dict = priorites[num-1]
                dir_list = dir_dict[dir[num]]
                my_dir = 0
                is_find = False
                for now_dir in dir_list:
                    nx, ny = i + dx[now_dir], j + dy[now_dir]
                    if nx < 0 or nx >= n or ny < 0 or ny >= n:
                        continue
                    if board[nx][ny] != [0,0]:
                        #자기 영역
                        if my_dir == 0 and board[nx][ny][0] == num:
                            my_dir = now_dir
                        continue
                    #빈 공간 찾음
                    is_find = True
                    dir[num] = now_dir
                    if next_sharks[nx][ny] == 0:
                        next_sharks[nx][ny] = num
                    else:
                        next_sharks[nx][ny] = min(next_sharks[nx][ny], num)
                        alive_sharks -= 1
                    break
                if not is_find:
                    nx, ny = i + dx[my_dir], j + dy[my_dir]
                    dir[num] = my_dir
                    next_sharks[nx][ny] = num
    sharks = next_sharks
    time += 1

if time > 1000:
    print(-1)
else:
    print(time)