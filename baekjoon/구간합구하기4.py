import sys
input = sys.stdin.readline
n, m = map(int, input().split())
arr = list(map(int, input().split()))
prefix_sum = [0]
sum_value = 0
for num in arr:
    sum_value += num
    prefix_sum.append(sum_value)

for _ in range(m):
    i, j = map(int, input().split())
    result = prefix_sum[j] - prefix_sum[i-1]
    print(result)
