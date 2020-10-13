import copy

n, m, t = map(int, input().split())
board = [[]] + [list(map(int, input().split())) for _ in range(n)]
opers = [list(map(int, input().split())) for _ in range(t)]
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]


def rotate(num, dir, move_k):
    lst = board[num]
    new_lst = [0] * m
    # 시계방향
    if dir == 0:
        for i in range(m):
            new_i = (i + move_k) % m
            new_lst[new_i] = lst[i]
    else:
        for i in range(m):
            new_i = (i - move_k) % m
            new_lst[new_i] = lst[i]
    return new_lst


for x, d, k in opers:
    for i in range(1, n + 1):
        # x 배수일때
        if i % x == 0:
            temp_lst = rotate(i, d, k)
            board[i] = temp_lst
    is_adj = False
    temp = copy.deepcopy(board)
    for i in range(1, n + 1):
        for j in range(m):
            # 지워진 수
            if board[i][j] == 0:
                continue
            for dir in range(4):
                nx, ny = i + dx[dir], (j + dy[dir]) % m
                if nx <= 0 or nx > n:
                    continue
                # 인접하면서 수가 같은 거
                if board[i][j] == board[nx][ny]:
                    is_adj = True
                    temp[i][j] = 0
                    temp[nx][ny] = 0
    board = copy.deepcopy(temp)
    # 인접하면서 같은 수 없을때
    if not is_adj:
        sum_value = 0
        cnt = 0
        for i in range(1, n + 1):
            for j in range(m):
                if board[i][j] == 0:
                    continue
                sum_value += board[i][j]
                cnt += 1

        avg = sum_value / cnt
        for i in range(1, n + 1):
            for j in range(m):
                if board[i][j] == 0:
                    continue
                if board[i][j] > avg:
                    board[i][j] -= 1
                elif board[i][j] < avg:
                    board[i][j] += 1

answer = 0
for i in range(1, n + 1):
    answer += sum(board[i])
print(answer)
