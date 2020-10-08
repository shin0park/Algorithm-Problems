#첫번째 풀이
'''
뒤에서 부터 거꾸로 dp 계산
dp[i] --> i번째 부터 끝까지의 최대 수익값
'''
N = int(input())
schedule = [list(map(int, input().split())) for _ in range(N)]
dp = [0 for _ in range(N+2)]
answer = 0

for i in range(N, 0,-1):
    t, p = schedule[i-1]
    if i + t - 1 <= N:
        dp[i] = max((p + dp[t + i]), answer)
        answer = dp[i]
    else:
        dp[i] = answer
        
print(answer)

