from itertools import combinations
import math

def solution(nums):
    answer = 0
    sum_list = list(map(sum, combinations(nums, 3)))
    for sum_num in sum_list:
        is_prime = True
        for i in range(2, int(math.sqrt(sum_num)) + 1):
            if sum_num % i == 0:
                is_prime = False
                break
        if is_prime:
            answer += 1
    return answer
