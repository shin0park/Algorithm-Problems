from itertools import combinations
n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
chicken = []
house = []
min_value = int(1e9)
for i in range(n):
    for j in range(n):
        if board[i][j] == 1:
            house.append([i,j])
        elif board[i][j] == 2:
            chicken.append([i,j])
            
for selected in combinations(chicken, m):
    sum_dist = 0
    for hx, hy in house:
        chicken_dist = int(1e9)
        for cx, cy in selected:
            chicken_dist = min(chicken_dist, abs(hx-cx)+abs(hy-cy))
        sum_dist += chicken_dist
    min_value = min(min_value, sum_dist)
    
print(min_value)
