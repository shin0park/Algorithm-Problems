from itertools import combinations

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
house = []
chicken = []
for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            house.append([i, j])
        elif board[i][j] == 2:
            chicken.append([i, j])

min_value = int(1e9)
for selected in combinations(chicken, M):
    total_chicken_dist = 0
    for hx, hy in house:
        chicken_dist = int(1e9)
        for cx, cy in selected:
            chicken_dist = min(chicken_dist, abs(cx - hx) + abs(cy - hy))
        total_chicken_dist += chicken_dist
    min_value = min(min_value, total_chicken_dist)
print(min_value)
