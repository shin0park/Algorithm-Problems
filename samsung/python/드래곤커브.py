'''
드래곤 커브의 정보는 네 정수 x, y, d, g로 이루어져 있다.
x와 y는 드래곤 커브의 시작 점, d는 시작 방향, g는 세대이다.
(0 ≤ x, y ≤ 100, 0 ≤ d ≤ 3, 0 ≤ g ≤ 10)
다음 문제에서 0 ≤ x, y ≤ 100이므로 크기는 101이 되어야 한다.
100으로 처음에 설정하여 런타임 에러 남
실수 조심
'''
n = int(input())
m = 101
board = [[0] * m for _ in range(m)]


def translation(curve, dx, dy):
    result = []
    for i, j in curve:
        result.append([i + dx, j + dy])
    return result


def rotate_counter_90(curve):
    result = []
    for i, j in curve:
        result.append([j, -i])
    return result


def new_generation_curve(curve):
    result = []
    end_x, end_y = curve[-1]
    trans_curve = translation(curve, -end_x, -end_y)
    for i, j in trans_curve:
        result.append([-j, i])
    result = translation(result, end_x, end_y)
    result = result[::-1]
    return curve + result[1:]


def draw_curve(generation):
    curve = [[0, 0], [1, 0]]
    if generation == 0:
        return curve
    for g in range(1, generation + 1):
        curve = new_generation_curve(curve)
    return curve


answer = 0
for i in range(n):
    x, y, d, g = map(int, input().split())
    temp = draw_curve(g)
    for i in range(d):
        temp = rotate_counter_90(temp)
    temp = translation(temp, x, y)
    for i, j in temp:
        board[i][j] = 1

for i in range(m - 1):
    for j in range(m - 1):
        if board[i][j] == 0:
            continue
        if board[i][j + 1] == 1 and board[i + 1][j] == 1 and board[i + 1][j + 1] == 1:
            answer += 1
print(answer)
