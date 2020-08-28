def solution(n, s):
    if s < n:
        return [-1]
    quo = s // n
    rem = s % n
    answer = [quo] * n
    i = 0
    if rem != 0:
        while rem:
            answer[n - i - 1] += 1
            rem -= 1
            i += 1
    return answer
