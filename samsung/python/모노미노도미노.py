n = int(input())
r, c = 4, 6
turn = []
for i in range(n):
    t, x, y = map(int, input().split())
    turn.append([t, x, y])

green_board = [[0] * 4 for _ in range(6)]
blue_board = [[0] * 6 for _ in range(4)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def my_print(arr, n, m):
    for i in range(n):
        for j in range(m):
            print(arr[i][j], end=" ")
        print()
    print()


def moving_to_blue(t, block, cnt):
    if t == 1:
        x, y = block[0]
        while True:
            nx, ny = x, y + 1
            if ny >= c or blue_board[nx][ny] != 0:
                break
            x, y = nx, ny
        blue_board[x][y] = cnt
    elif t == 2:
        x, y = block[1]
        while True:
            nx, ny = x, y + 1
            if ny >= c or blue_board[nx][ny] != 0:
                break
            x, y = nx, ny
        blue_board[x][y] = cnt
        blue_board[x][y - 1] = cnt
    elif t == 3:
        x1, y1 = block[0]
        x2, y2 = block[1]
        while True:
            nx1, ny1, nx2, ny2 = x1, y1 + 1, x2, y2 + 1
            if ny1 >= c or ny2 >= c or blue_board[nx1][ny1] != 0 or blue_board[nx2][ny2] != 0:
                break
            x1, y1 = nx1, ny1
            x2, y2 = nx2, ny2
        blue_board[x1][y1] = cnt
        blue_board[x2][y2] = cnt


def moving_to_green(t, block, cnt):
    if t == 1:
        x, y = block[0]
        while True:
            nx, ny = x + 1, y
            if nx >= c or green_board[nx][ny] != 0:
                break
            x, y = nx, ny
        green_board[x][y] = cnt
    elif t == 2:
        x1, y1 = block[0]
        x2, y2 = block[1]
        while True:
            nx1, ny1, nx2, ny2 = x1 + 1, y1, x2 + 1, y2
            if nx1 >= c or nx2 >= c or green_board[nx1][ny1] != 0 or green_board[nx2][ny2] != 0:
                break
            x1, y1 = nx1, ny1
            x2, y2 = nx2, ny2
        green_board[x1][y1] = cnt
        green_board[x2][y2] = cnt
    elif t == 3:
        x, y = block[1]
        while True:
            nx, ny = x + 1, y
            if nx >= c or green_board[nx][ny] != 0:
                break
            x, y = nx, ny
        green_board[x][y] = cnt
        green_board[x - 1][y] = cnt


def full_green_remove(board):
    result = []
    answer = 0
    light_color_cnt = 0
    for i in range(6):
        block_cnt = 0
        for j in range(4):
            if green_board[i][j] == 0:
                break
            block_cnt += 1
        if block_cnt == 4:
            result.append(i)
    for i in result:
        for j in range(4):
            green_board[i][j] = 0
    answer += len(result)
    update_green_board()
    # 연한색
    for i in range(2):
        for j in range(4):
            if green_board[i][j] != 0:
                light_color_cnt += 1
                break
    if light_color_cnt == 2:
        result = [4, 5]
    elif light_color_cnt == 1:
        result = [5]
    if not light_color_cnt == 0:
        for i in result:
            for j in range(4):
                green_board[i][j] = 0
        update_green_board()
    return answer


def full_blue_remove(board):
    result = []
    answer = 0
    light_color_cnt = 0
    for i in range(6):
        block_cnt = 0
        for j in range(4):
            if blue_board[j][i] == 0:
                break
            block_cnt += 1
        if block_cnt == 4:
            result.append(i)
    for i in result:
        for j in range(4):
            blue_board[j][i] = 0
    answer += len(result)
    update_blue_board()
    # 연한 색의 경우
    for i in range(2):
        for j in range(4):
            if blue_board[j][i] != 0:
                light_color_cnt += 1
                break
    if light_color_cnt == 2:
        result = [4, 5]
    elif light_color_cnt == 1:
        result = [5]
    if not light_color_cnt == 0:
        for i in result:
            for j in range(4):
                blue_board[j][i] = 0
        update_blue_board()
    return answer


def update_green_board():
    for i in range(5, -1, -1):
        for j in range(4):
            if green_board[i][j] == 0:
                continue
            num = green_board[i][j]
            type = 1
            # 2
            if j > 0 and green_board[i][j - 1] == num:
                green_board[i][j - 1], green_board[i][j] = 0, 0
                block = [[i, j - 1], [i, j]]
                type = 2
                moving_to_green(type, block, num)
            elif j < 3 and green_board[i][j + 1] == num:
                green_board[i][j], green_board[i][j + 1] = 0, 0
                block = [[i, j], [i, j + 1]]
                type = 2
                moving_to_green(type, block, num)
            # 3
            elif i > 0 and green_board[i - 1][j] == num:
                green_board[i - 1][j], green_board[i][j] = 0, 0
                block = [[i - 1, j], [i, j]]
                type = 3
                moving_to_green(type, block, num)
            elif i < 5 and green_board[i + 1][j] == num:
                green_board[i + 1][j], green_board[i][j] = 0, 0
                block = [[i, j], [i + 1, j]]
                type = 3
                moving_to_green(type, block, num)
            # 1
            else:
                green_board[i][j] = 0
                block = [[i, j]]
                type = 1
                moving_to_green(type, block, num)


def update_blue_board():
    for j in range(5, -1, -1):
        for i in range(4):
            if blue_board[i][j] == 0:
                continue
            num = blue_board[i][j]
            type = 1
            # 2
            if j > 0 and blue_board[i][j - 1] == num:
                blue_board[i][j - 1], blue_board[i][j] = 0, 0
                block = [[i, j - 1], [i, j]]
                type = 2
                moving_to_blue(type, block, num)
            elif j < 5 and blue_board[i][j + 1] == num:
                blue_board[i][j], blue_board[i][j + 1] = 0, 0
                block = [[i, j], [i, j + 1]]
                type = 2
                moving_to_blue(type, block, num)
            # 3
            elif i > 0 and blue_board[i - 1][j] == num:
                blue_board[i - 1][j], blue_board[i][j] = 0, 0
                block = [[i - 1, j], [i, j]]
                type = 3
                moving_to_blue(type, block, num)
            elif i < 3 and blue_board[i + 1][j] == num:
                blue_board[i + 1][j], blue_board[i][j] = 0, 0
                block = [[i, j], [i + 1, j]]
                type = 3
                moving_to_blue(type, block, num)
            # 1
            else:
                blue_board[i][j] = 0
                block = [[i, j]]
                type = 1
                moving_to_blue(type, block, num)


total_score = 0
for game in range(n):
    cnt = game + 1
    t, x, y = turn[game]
    if t == 1:
        green_block = [[0, y]]
        blue_block = [[x, 0]]
        moving_to_green(t, green_block, cnt)
        moving_to_blue(t, blue_block, cnt)
    elif t == 2:
        block = [[x, y], [x, y + 1]]
        green_block = [[0, y], [0, y + 1]]
        blue_block = [[x, 0], [x, 1]]
        moving_to_green(t, green_block, cnt)
        moving_to_blue(t, blue_block, cnt)
    elif t == 3:
        block = [[x, y], [x + 1, y]]
        green_block = [[0, y], [1, y]]
        blue_block = [[x, 0], [x + 1, 0]]
        moving_to_green(t, green_block, cnt)
        moving_to_blue(t, blue_block, cnt)
    cnt += 1
    while True:
        green_score = full_green_remove(green_board)
        blue_score = full_blue_remove(blue_board)
        total_score += (green_score + blue_score)
        if green_score == 0 and blue_score == 0:
            break

remain = 0
for i in range(6):
    for j in range(4):
        if green_board[i][j] != 0:
            remain += 1
        if blue_board[j][i] != 0:
            remain += 1
print(total_score)
print(remain)
