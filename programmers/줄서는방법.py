#첫번째 풀이

import math

def solution(n, k):
    answer = []
    arr = [i for i in range(1, n+1)]
    while n > 0:
        front_cnt = math.factorial(n-1)
        index = k // front_cnt
        if k % front_cnt == 0:
            index -= 1
        answer.append(arr[index])
        arr.remove(arr[index])
        k %= front_cnt
        n -= 1
        
    return answer

#두번째 풀이
import math

def solution(n, k):
    answer = []
    arr = [i for i in range(1, n+1)]
    while n > 0:
        fact = math.factorial(n-1)
        answer.append(arr.pop((k-1)//fact))
        n , k = n-1, k % fact
    return answer
