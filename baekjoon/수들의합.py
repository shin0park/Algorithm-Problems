import sys
input = sys.stdin.readline
n, m = map(int, input().split())
arr = list(map(int, input().split()))
end = 0
sum_value = 0
cnt = 0
for start in range(n):
    while end < n and (start < n and sum_value < m):
        sum_value += arr[end]
        end += 1
    if sum_value == m:
        cnt += 1
    sum_value -= arr[start]
print(cnt)