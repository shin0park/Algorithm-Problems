import copy
from itertools import product

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def back(dir):
    if dir == 0 or dir == 1:
        return dir + 2
    else:
        return dir - 2


def rotate_90(dir):
    return (dir + 1) % 4


def cctv_one_direct(x, y, dir, board):
    while True:
        nx, ny = x + dx[dir], y + dy[dir]
        if nx < 0 or nx >= n or ny < 0 or ny >= m or board[nx][ny] == 6:
            break
        board[nx][ny] = '#'
        x, y = nx, ny
    return board


def run_cctv(x, y, cctv_num, dir, board):
    # cctv
    if cctv_num == 1:
        cctv_one_direct(x, y, dir, board)
    elif cctv_num == 2:
        cctv_one_direct(x, y, dir, board)
        cctv_one_direct(x, y, back(dir), board)
    elif cctv_num == 3:
        cctv_one_direct(x, y, dir, board)
        cctv_one_direct(x, y, rotate_90(dir), board)
    elif cctv_num == 4:
        for i in range(4):
            if i == dir:
                continue
            cctv_one_direct(x, y, i, board)
    else:
        for i in range(4):
            cctv_one_direct(x, y, i, board)


cctv_dir = [0, 1, 2, 3]
cctv_cnt = 0
cctv_list = []
for i in range(n):
    for j in range(m):
        if 1 <= board[i][j] <= 5:
            cctv_cnt += 1
            cctv_list.append([board[i][j], i, j])

min_value = int(1e9)
for com in product(cctv_dir, repeat=cctv_cnt):
    empty_cnt = 0
    new_board = copy.deepcopy(board)
    for i, cctv in enumerate(cctv_list):
        cnum, cx, cy = cctv
        run_cctv(cx, cy, cnum, com[i], new_board)
    for i in range(n):
        for j in range(m):
            if new_board[i][j] == 0:
                empty_cnt += 1
    min_value = min(min_value, empty_cnt)
print(min_value)
