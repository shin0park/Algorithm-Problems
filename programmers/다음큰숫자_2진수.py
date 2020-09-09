#첫번째 풀이
def binary_one_num(num):
    result = 0
    while num != 0:
        if num % 2 == 1:
            result += 1
        num //= 2
    return result

def solution(n):
    answer = n + 1
    binary_n = binary_one_num(n)
    while True:
        new_binary_n = binary_one_num(answer)
        if binary_n == new_binary_n:
            break
        answer += 1
    return answer


#두번째 풀이
'''
python에 bin 함수로 이진수로 바꿔주는 함수가 있다.
'''
def solution(n):
    answer = n + 1
    binary_n = bin(n).count('1')
    while True:
        new_binary_n = bin(answer).count('1')
        if binary_n == new_binary_n:
            break
        answer += 1
    return answer
