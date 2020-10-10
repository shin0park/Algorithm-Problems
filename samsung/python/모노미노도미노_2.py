'''
이전에 green과 blue를 따로 구현했지만 blue를 90도 회전하여 통합하여 다시 구현
더 간략한 코드
'''
n = int(input())
r, c = 4, 6
turn = []
for i in range(n):
    t, x, y = map(int, input().split())
    turn.append([t, x, y])

green_board = [[0] * 4 for _ in range(6)]
blue_board = [[0] * 4 for _ in range(6)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def change_block(block):
    t, x, y = block
    if t == 1:
        return (1,0,y), (1,0,x)
    elif t == 2:
        return (2,0,y), (3,0,x)
    elif t == 3:
        return (3,0,y), (2,0,x)

def moving(block, cnt, board):
    t, x, y = block
    if t == 1:
        while True:
            nx, ny = x + 1, y
            if nx >= c or board[nx][ny] != 0:
                break
            x, y = nx, ny
        board[x][y] = cnt
    elif t == 2:
        x1, y1 = x, y
        x2, y2 = x, y + 1
        while True:
            nx1, ny1, nx2, ny2 = x1 + 1, y1, x2 + 1, y2
            if nx1 >= c or nx2 >= c or board[nx1][ny1] != 0 or board[nx2][ny2] != 0:
                break
            x1, y1 = nx1, ny1
            x2, y2 = nx2, ny2
        board[x1][y1] = cnt
        board[x2][y2] = cnt
    elif t == 3:
        x, y = x + 1, y
        while True:
            nx, ny = x + 1, y
            if nx >= c or board[nx][ny] != 0:
                break
            x, y = nx, ny
        board[x][y] = cnt
        board[x - 1][y] = cnt

# 꽉찬 행 지우기 그 이후 연한색에 보드 있는 경우 아래 줄 삭제
def full_remove(board):
    result = []
    answer = 0
    light_color_cnt = 0
    for i in range(6):
        block_cnt = 0
        for j in range(4):
            if board[i][j] == 0:
                break
            block_cnt += 1
        if block_cnt == 4:
            result.append(i)
    for i in result:
        for j in range(4):
            board[i][j] = 0
    answer += len(result)
    if result:
        update_board(board)
    # 연한색
    for i in range(2):
        for j in range(4):
            if board[i][j] != 0:
                light_color_cnt += 1
                break
    if light_color_cnt == 2:
        result = [4, 5]
    elif light_color_cnt == 1:
        result = [5]
    if not light_color_cnt == 0:
        for i in result:
            for j in range(4):
                board[i][j] = 0
        update_board(board)
    return answer

def update_board(board):
    for i in range(5, -1, -1):
        for j in range(4):
            if board[i][j] == 0:
                continue
            num = board[i][j]
            #블록 덩어리 찾기
            # 2
            if j > 0 and board[i][j - 1] == num:
                board[i][j - 1], board[i][j] = 0, 0
                block = [2, i, j - 1]
                moving(block, num, board)
            elif j < 3 and board[i][j + 1] == num:
                board[i][j], board[i][j + 1] = 0, 0
                block = [2, i, j]
                moving(block, num, board)
            # 3
            elif i > 0 and board[i - 1][j] == num:
                board[i - 1][j], board[i][j] = 0, 0
                block = [3, i - 1, j]
                moving(block, num, board)
            elif i < 5 and board[i + 1][j] == num:
                board[i + 1][j], board[i][j] = 0, 0
                block = [3, i, j]
                moving(block, num, board)
            # 1
            else:
                board[i][j] = 0
                block = [1, i, j]
                moving(block, num, board)
total_score = 0
for game in range(n):
    cnt = game + 1
    green_block, blue_block = change_block(turn[game])
    moving(green_block, cnt, green_board)
    moving(blue_block, cnt, blue_board)
    cnt += 1
    while True:
        green_score = full_remove(green_board)
        blue_score = full_remove(blue_board)
        total_score += (green_score + blue_score)
        if green_score == 0 and blue_score == 0:
            break

remain = 0
for i in range(6):
    for j in range(4):
        if green_board[i][j] != 0:
            remain += 1
        if blue_board[i][j] != 0:
            remain += 1
print(total_score)
print(remain)
