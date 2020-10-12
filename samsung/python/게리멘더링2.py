n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]


def divide_area(x, y, d1, d2):
    area = [[0] * (n + 1) for _ in range(n + 1)]
    if (1 <= x < x + d1 + d2 <= n) and (1 <= y - d1 < y) and (y < y + d2 <= n):
        # 1 area
        for i in range(1, x + d1):
            for j in range(1, y + 1):
                area[i][j] = 1
        # 2 area
        for i in range(1, x + d2 + 1):
            for j in range(y + 1, n + 1):
                area[i][j] = 2
        # 3 area
        for i in range(x + d1, n + 1):
            for j in range(1, y - d1 + d2):
                area[i][j] = 3
        # 4 area
        for i in range(x + d2 + 1, n + 1):
            for j in range(y - d1 + d2, n + 1):
                area[i][j] = 4
        # 5 area
        for i in range(d1 + 1):
            nx, ny = x + i, y - i
            area[nx][ny] = 5
            nx, ny = x + d2 + i, y + d2 - i
            area[nx][ny] = 5
        for i in range(d2 + 1):
            nx, ny = x + i, y + i
            area[nx][ny] = 5
            nx, ny = x + d1 + i, y - d1 + i
            area[nx][ny] = 5
        for i in range(1, n + 1):
            start_y, end_y = 0, 0
            cnt = 0
            is_vaild = False
            for j in range(1, n + 1):
                if cnt == 0 and area[i][j] == 5:
                    start_y = j + 1
                    is_vaild = True
                    cnt = 1
                    continue
                if cnt == 1 and area[i][j] == 5:
                    end_y = j
            if end_y != 0 and is_vaild:
                for j in range(start_y, end_y):
                    area[i][j] = 5
        return area
    return False


def get_score(new_area):
    score = [0, 0, 0, 0, 0]
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            score[new_area[i][j] - 1] += board[i - 1][j - 1]
    score.sort()
    return score[-1] - score[0]


min_value = int(1e9)
for x in range(1, n + 1):
    for y in range(1, n + 1):
        for d1 in range(1, n):
            for d2 in range(1, n):
                new_area = divide_area(x, y, d1, d2)
                if new_area:
                    min_value = min(min_value, get_score(new_area))
print(min_value)
