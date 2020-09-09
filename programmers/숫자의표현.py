#첫번째 풀이
def solution(n):
    answer = 0
    for i in range(1, n+1):
        start = i
        sum_n = 0
        while sum_n < n:
            sum_n += start
            start += 1
        if sum_n == n:
            answer += 1
    return answer
