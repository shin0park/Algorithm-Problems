'''
<2차원 리스트 90도 회전>
    n - 행 길이 , m - 열 길이
    시계방향으로 90도 회전 
    (x, y) --> (y, n - x -1)
	
    반시계방향으로 90도 회전 
    (x, y) --> (m - y - 1, x)
'''


# 시계방향으로 90도 회전 구현 함수
def rotate_a_matrix_by_90_degree(a):
    n = len(a)  # 행 길이
    m = len(a[0])  # 열 길이
    result = [[0] * n for _ in range(m)]  # 회전 시 행과 열의 길이가 바뀐다.
    for i in range(n):
        for j in range(m):
            result[j][n - i - 1] = a[i][j]
    return result


a = [[0, 1, 0], [1, 1, 0]]
a_result = rotate_a_matrix_by_90_degree(a)
print(a)
print(a_result)
