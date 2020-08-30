#첫번째 풀이

import math
import itertools

#n까지의 수에서 소수 찾기 - 에라토스테네스의 체
def prime_numbers(max_number):
    number_list = [True for _ in range(max_number + 1)]
    number_list[0] = False
    number_list[1] = False
    for i in range(2, int(math.sqrt(max_number) + 1)):
        if number_list[i] == True:
            j = 2
            while (i * j) <= max_number:
                number_list[i * j] = False
                j += 1
    return number_list

def solution(numbers):
    answer = 0
    arr_num = []
    for s in numbers:
        arr_num.append(s)
    arr_num.sort(reverse = True)
    temp = arr_num
    max_number = int(''.join(temp))
    prime_list = prime_numbers(max_number)

    for i in range(1, len(numbers) + 1):
        for x in itertools.permutations(arr_num, i):
            num = int(''.join(list(x)))
            if prime_list[num]:
                prime_list[num] = False
                answer += 1
    return answer
