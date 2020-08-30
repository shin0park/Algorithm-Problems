#첫번째 풀이

from itertools import product
arr = [None] * 20
cal = ['+', '-']
permutes = []
def getResult(inx, k):
    if inx >= k:
        permutes.append(arr[0:k])
        return
    for c in cal:
        arr[inx] = c
        getResult(inx + 1, k)
        
def solution(numbers, target):
    answer = 0
    getResult(0,len(numbers))

    for permute in permutes:
        total = 0
        for j, num in enumerate(numbers):
            if permute[j] == '+':
                total += num
            else:
                total -= num
        if total == target:
            answer += 1
    return answer

#두번째 풀이
'''
재귀를 이용한 풀이
'''
def solution(numbers, target):
    if not numbers and target == 0 :
        return 1
    elif not numbers:
        return 0
    else:
        return solution(numbers[1:], target-numbers[0]) + solution(numbers[1:], target+numbers[0])
