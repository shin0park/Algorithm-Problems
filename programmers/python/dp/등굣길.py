#첫번째 풀이
'''
문제
가장 왼쪽 위, 즉 집이 있는 곳의 좌표는 (1, 1)로 나타내고
가장 오른쪽 아래, 즉 학교가 있는 곳의 좌표는 (m, n)으로 나타냅니다.
문제에서 주어지는 좌표는 (x,y)
배열에 넣을때는 뒤집어 줘야 한다. -- 실수
a[x][y] - x
a[y][x] - o
 행 / 열
'''
def solution(m, n, puddles):
    mod = 1000000007
    puddle_check = [[False] * (m + 1) for _ in range(n + 1)] 
    d = [[0] * (m + 1) for _ in range(n + 1)] 
    for j, i in puddles:
        puddle_check[i][j] = True
    d[1][1] = 1
    for i in range(1, n+1):
        for j in range(1, m+1):
            if puddle_check[i][j] or (i == 1 and j == 1):
                continue
            d[i][j] = (d[i][j-1] + d[i-1][j]) % mod
    return d[n][m]
