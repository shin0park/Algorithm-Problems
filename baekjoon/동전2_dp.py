INF = int(1e9)
n, k = map(int,input().split())
coins = []
for _ in range(n):
  coins.append(int(input()))

# 동전을만들수 없는 경우는 동전의 가치를 넘는 100001로 설정해준다.
MAX = 100001
d = [MAX for _ in range(k + 1)] 

d[0] = 0
for coin in coins:
    for i in range(coin, k + 1):
        d[i] = min(d[i], d[i - coin] + 1)
  
if d[k] == MAX: #예외처리 주의
    print(-1)
else:
    print(d[k])
