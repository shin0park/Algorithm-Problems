import math

n = int(input())
candidate = list(map(int, input().split()))
b, c = map(int, input().split())
answer = 0
for cand in candidate:
    num = cand
    # 총감독
    answer += 1
    if num <= b:
        continue
    num -= b
    answer += (math.ceil(num / c))
print(answer)
