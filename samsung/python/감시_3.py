from copy import deepcopy
def fill(x, y, arr, d):
    for i in d:
        nx, ny = x, y
        while True:
            nx += dx[i]
            ny += dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if arr[nx][ny] == 6:
                    break
                elif arr[nx][ny] == 0:
                    arr[nx][ny] = "#"
            else:
                break
def dfs(arr, cnt):
    global min_value
    temp = deepcopy(arr)
    if cnt == cctv_cnt:
        num = 0
        for i in range(n):
            num += temp[i].count(0)
        min_value = min(min_value, num)
        return
    x, y, cctv = cctv_list[cnt]
    for i in direction[cctv]:
        fill(x, y, temp, i)
        dfs(temp, cnt + 1)
        temp = deepcopy(arr)
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
direction = [[], [[0], [1], [2], [3]], [[0, 1], [2, 3]], [[3, 0], [0, 2], [2, 1], [1, 3]],
[[1, 3, 0], [3, 0, 2], [0, 2, 1], [2, 1, 3]], [[0, 1, 2, 3]]]
n, m = map(int, input().split())
board = []
cctv_list = []
cctv_cnt = 0
min_value = int(1e9)
for i in range(n):
    a = list(map(int, input().split()))
    board.append(a)
    for j in range(len(a)):
        if a[j] != 0 and a[j] != 6:
            cctv_list.append([i, j, a[j]])
            cctv_cnt += 1
dfs(board, 0)
print(min_value)