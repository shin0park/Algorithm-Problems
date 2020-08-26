#첫번째 풀이

def solution(triangle):
    answer = 0
    n = len(triangle)
    max_triangle = triangle[-1]
    for i in range(1, n):
        cur_triangle = triangle[len(triangle) - i - 1]
        current_max = []
        for j in range(0, len(max_triangle)-1):
            max_value = max(max_triangle[j], max_triangle[j+1]) + cur_triangle[j]
            current_max.append(max_value)
        max_triangle = current_max
    answer = max_triangle[0]
    return answer
