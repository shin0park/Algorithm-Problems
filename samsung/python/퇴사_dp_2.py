n = int(input())
works = [list(map(int, input().split())) for _ in range(n)]
d = [0] * (n+1)
for i in range(1, n+1):
    t, p = works[i-1]
    if i + t - 1 <= n:
        d[i + t - 1] = max(d[i + t - 1], p + d[i - 1])
    d[i] = max(d[i-1], d[i])
print(d[n])