from collections import deque

n = int(input())
k = int(input())
board = [[0] * n for _ in range(n)]
dx = [0, 0, -1, 0, 1]
dy = [0, 1, 0, -1, 0]
for i in range(k):
    x, y = map(int, input().split())
    # 사과
    board[x - 1][y - 1] = 2

turn = {}
l = int(input())
for i in range(l):
    x, c = input().split()
    x = int(x)
    turn[x] = c


def turn_dir(dir, c):
    # 오른쪽으로 90 회전
    if c == 'D':
        if dir == 1:
            return 4
        else:
            return dir - 1
    else:
        if dir == 4:
            return 1
        else:
            return dir + 1


time = 0
snake = deque([(0, 0)])
head_x, head_y, dir = 0, 0, 1
tail_x, tail_y = 0, 0
# 뱀
board[head_x][head_y] = 1
while True:
    time += 1
    head_x, head_y = snake[0]
    tail_x, tail_y = snake[-1]
    nx, ny = head_x + dx[dir], head_y + dy[dir]
    # 뱀이 벽에 부딪히거나 자신의 몸에 부딪힐때
    if nx < 0 or nx >= n or ny < 0 or ny >= n or board[nx][ny] == 1:
        break
    # 사과 없을 경우
    if board[nx][ny] != 2:
        board[tail_x][tail_y] = 0
        snake.pop()
    board[nx][ny] = 1
    snake.appendleft((nx, ny))
    if turn.get(time) != None:
        dir = turn_dir(dir, turn[time])

print(time)
