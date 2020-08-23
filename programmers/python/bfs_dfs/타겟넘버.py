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
