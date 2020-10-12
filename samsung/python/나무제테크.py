n, m, k = map(int, input().split())
food = [[5] * n for _ in range(n)]
give_food = [list(map(int, input().split())) for _ in range(n)]
tree = [[None] * n for _ in range(n)]
dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]
for i in range(n):
    for j in range(n):
        tree[i][j] = []

for i in range(m):
    x, y, z = map(int, input().split())
    tree[x - 1][y - 1].append(z)


def breeding(x, y):
    for i in range(8):
        nx, ny = x + dx[i], y + dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            continue
        tree[nx][ny].append(1)


for year in range(k):
    die = [[None] * n for _ in range(n)]
    # 봄
    for i in range(n):
        for j in range(n):
            if tree[i][j]:
                tree[i][j].sort()
                tree_list = tree[i][j]
                for num, age in enumerate(tree_list):
                    if food[i][j] >= age:
                        food[i][j] -= age
                        tree_list[num] += 1
                    else:
                        tree[i][j] = tree_list[:num]
                        die[i][j] = tree_list[num:]
                        break
    # 여름
    for i in range(n):
        for j in range(n):
            if die[i][j]:
                die_list = die[i][j]
                for age in die_list:
                    food[i][j] += (age // 2)
    # 가을
    for i in range(n):
        for j in range(n):
            if tree[i][j]:
                tree_list = tree[i][j]
                for age in tree_list:
                    if age % 5 == 0:
                        breeding(i, j)
    # 겨울
    for i in range(n):
        for j in range(n):
            food[i][j] += give_food[i][j]

answer = 0
for i in range(n):
    for j in range(n):
        if tree[i][j]:
            answer += len(tree[i][j])
print(answer)
