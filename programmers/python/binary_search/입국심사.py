#첫번째 풀이

import math

def binary_search(start, end, n, times):
    min_value = end
    while start <= end:
        mid = (start + end) // 2
        able_people = 0
        for time in times:
            able_people += (mid // time)
        if able_people < n:
            start = mid + 1
        else:
            min_value = min(min_value, mid)
            end = mid - 1
    return min_value

def solution(n, times):
    answer = 0
    times.sort()
    start = (n // len(times)) * times[0] 
    end = math.ceil(n / len(times)) * times[-1]
    answer = binary_search(start, end, n, times)
    return answer


#두번째 풀이
def solution(n, times):
    answer = 0
    start, end, mid = 1, times[-1] * n, 0

    while start < end:
        mid = (start + end) // 2
        able_people = 0
        for time in times:
            able_people += mid // time

        if able_people >= n:
            end = mid
        else:
            start = mid + 1
    answer = start
    return answer
