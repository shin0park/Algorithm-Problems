from collections import deque

dx = [0,0,-1,0,1]#행
dy = [0,1,0,-1,0]#열

def rotate_clockwise(direct):
    if direct == 1:
        return 4
    else:
        return direct - 1
    
def rotate_counter_clockwise(direct):
    if direct == 4:
        return 1
    else:
        return direct + 1
    
n = int(input())
k = int(input())
board = [[0] * n for _ in range(n)]
for i in range(k):
    r, c = map(int, input().split())
    board[r-1][c-1] = 1 #apple
l = int(input())
dict_dir = {}
for i in range(l):
    second, direct = input().split()
    dict_dir[int(second)] = direct

snake = deque([])
time = 0
direct = 1
x, y = 0, 0
board[x][y] = 2 #snake
snake.append([x,y])
while True:
    time += 1
    x = x + dx[direct]
    y = y + dy[direct]
    if (x < 0 or x >= n or y < 0 or y >= n) or board[x][y] == 2:
        break
    elif board[x][y] == 1:
        board[x][y] = 2
    else:
        board[x][y] = 2
        rx, ry = snake.popleft()
        board[rx][ry] = 0
    snake.append([x,y])
    if time in dict_dir:
        if dict_dir[time] == 'L':
            direct = rotate_counter_clockwise(direct)
        else:
            direct = rotate_clockwise(direct)
    
print(time)
    
