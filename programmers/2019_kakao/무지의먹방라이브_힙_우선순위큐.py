'''
힙을 써서 최소의 time을 pop하며 구현하는 방식은 잘생각했으나
이후 구현과정에서 좀 꼬임.
'''
import heapq

def solution(food_times, k):
    answer = 0
    length = len(food_times)
    if sum(food_times) <= k:
        return -1
    q = []
    for i,time in enumerate(food_times):
        heapq.heappush(q, (time, i+1))
    previous = 0
    sum_value = 0
    while k - sum_value >= length * (q[0][0] - previous):
        time = q[0][0]
        sum_value += length * (time - previous)
        previous = time
        heapq.heappop(q)
        length -= 1
    result = sorted(q, key = lambda x: x[1])
    answer = result[(k - sum_value) % length][1]
    return answer
