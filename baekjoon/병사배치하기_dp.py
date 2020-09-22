n = int(input())
score = list(map(int, input().split()))
d = [ 1 for _ in range(n)]

for i in range(n):
    temp = 0
    for j in range(i,-1,-1):
        if score[i] < score[j]:
            d[i] = max(d[i], d[j] + 1)

print(len(score) - max(d))
