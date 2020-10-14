'''
이전의 중복순열 풀이 이외에
dfs로 풀이
product로 중복순열 모든 경우 구한다음 시뮤레이션 했던 방식이 2배 더 빠름
'''

from copy import deepcopy

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
dir_list = [[], [[0], [1], [2], [3]], [[0, 2], [1, 3]], [[0, 3], [0, 1], [1, 2], [2, 3]],
            [[0, 2, 3], [0, 1, 3], [0, 1, 2], [1, 2, 3]], [[0, 1, 2, 3]]]


def run_cctv(x, y, dir_list, board):
    for dir in dir_list:
        nx, ny = x, y
        while True:
            nx += dx[dir]
            ny += dy[dir]
            if nx < 0 or nx >= n or ny < 0 or ny >= m or board[nx][ny] == 6:
                break
            board[nx][ny] = '#'


def dfs(cnt, arr):
    global min_value
    temp = deepcopy(arr)
    if cnt == cctv_cnt:
        empty_cnt = 0
        for i in range(n):
            for j in range(m):
                if temp[i][j] == 0:
                    empty_cnt += 1
        min_value = min(min_value, empty_cnt)
        return
    cctv_num, x, y = cctv_list[cnt]
    for dir in dir_list[cctv_num]:
        run_cctv(x, y, dir, temp)
        dfs(cnt + 1, temp)
        temp = deepcopy(arr)
    return


cctv_cnt = 0
cctv_list = []
for i in range(n):
    for j in range(m):
        if 1 <= board[i][j] <= 5:
            cctv_cnt += 1
            cctv_list.append([board[i][j], i, j])
min_value = int(1e9)
dfs(0, board)
print(min_value)
