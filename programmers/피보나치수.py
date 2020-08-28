#첫번째 풀이
'''
반복적
'''
def solution(n):
    mod = 1234567
    f = [0] * (n+1)
    f[0] = 0
    f[1] = 1
    for i in range(2, n+1):
        f[i] = (f[i-2] + f[i-1]) % mod
    return f[n]
