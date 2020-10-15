n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
block_list = [[[0, 0], [0, 1], [0, 2], [0, 3]], [[0, 0], [0, 1], [1, 0], [1, 1]], [[0, 0], [1, 0], [2, 0], [2, 1]],
              [[0, 0], [1, 0], [2, 0], [2, -1]],
              [[0, 0], [1, 0], [1, 1], [2, 1]], [[0, 0], [1, 0], [1, -1], [2, -1]], [[0, 0], [0, 1], [0, 2], [1, 1]],
              [[0, 0], [0, 1], [0, 2], [-1, 1]]]


def rotate_90_clock(block):
    result = []
    for i, j in block:
        result.append([-j, i])
    return result


def check(x, y, block):
    sum_value = 0
    for i in range(4):
        nx, ny = x + block[i][0], y + block[i][1]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            return False
        sum_value += board[nx][ny]
    return sum_value


answer = 0
for i in range(n):
    for j in range(m):
        for k in range(8):
            block = block_list[k]
            for l in range(4):
                sum_value = check(i, j, block)
                if sum_value:
                    answer = max(answer, sum_value)
                block = rotate_90_clock(block)
print(answer)
