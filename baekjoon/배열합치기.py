import sys
input = sys.stdin.readline
n, m = map(int, input().split())
arrA = list(map(int, input().split()))
arrB = list(map(int, input().split()))
i = 0
j = 0
k = 0
result = [0] * (n + m)
while k < (n + m):
    if j >= m or (i < n and arrA[i] <= arrB[j]):
        result[k] = arrA[i]
        i += 1
    else:
        result[k] = arrB[j]
        j += 1
    k += 1
for i in result:
    print(i, end=' ')