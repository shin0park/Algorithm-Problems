'''
처음에 시간 초과 실패 : 조합인 점 주의, deepcopy() 많이 할 경우 시초
dfs 수행 시 이전상태로 다시 되돌릴때 가능하면 deepcopy 없이 감시, 청소년 상어 문제처럼 되돌려야
할 것이 많을 경우에 deepcopy() 사용
'''
n, m, h = map(int, input().split())
ladder = [[0] * (n + 1) for _ in range(h + 1)]
for i in range(m):
    a, b = map(int, input().split())
    ladder[a][b] = 1
    ladder[a][b + 1] = 2
h += 1
n += 1
is_end = False
min_value = int(1e9)


def get_success(board):
    for c in range(1, n):
        temp = c
        for r in range(1, h):
            if board[r][temp] == 2:
                nx, ny = r, temp - 1
                if (0 < ny < n) and board[nx][ny] == 1:
                    temp = ny
            elif board[r][temp] == 1:
                nx, ny = r, temp + 1
                if (0 < ny < n) and board[nx][ny] == 2:
                    temp = ny
        if temp != c:
            return False
    return True


def dfs(x, y, cnt, board):
    global is_end, min_value
    if cnt >= min_value:
        return
    if get_success(board):
        is_end = True
        min_value = min(min_value, cnt)
        return
    elif cnt == 3:
        return
    for i in range(x, h):
        k = y if i == x else 1
        for j in range(k, n - 1):
            if board[i][j] == 0 and board[i][j + 1] == 0:
                # 사다리 세우기
                board[i][j] = 1
                board[i][j + 1] = 2
                dfs(i, j + 2, cnt + 1, board)
                board[i][j] = 0
                board[i][j + 1] = 0


if m == 0:
    print(0)
else:
    dfs(1, 1, 0, ladder)
    if is_end:
        print(min_value)
    else:
        print(-1)
