#첫번째 풀이
'''
비트연산 사용
'''
def solution(n, arr1, arr2):
    answer = []
    for i in range(len(arr1)):
        bin_str = bin(arr1[i] | arr2[i])[2:]
        answer.append(("0" * (n - len(bin_str)) + bin_str).replace("0", " ")
                                                        .replace("1", "#"))
    return answer


'''
비트연산 없이 풀기
'''
from collections import deque

def decode_binary(num, n):
    result = deque([])
    while num > 0:
        result.appendleft(num % 2)
        num //= 2
    while len(result) < n:
        result.appendleft(0)
    return list(result)

def solution(n, arr1, arr2):
    answer = []
    for one, two in zip(arr1, arr2):
        row1 = decode_binary(one, n)
        row2 = decode_binary(two, n)
        temp = ''
        for i, j in zip(row1, row2):
            if i == 0 and j == 0:
                temp += ' '
            else:
                temp += '#'
        answer.append(temp)
    return answer
