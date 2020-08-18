#첫번째 풀이

import heapq

def solution(scoville, K):
    answer = 0
    h = []
    for score in scoville:
        heapq.heappush(h, score)
    while True:
        first_min_score = heapq.heappop(h)
        if first_min_score >= K:
            return answer
        elif len(h) <= 0:
            break;
        second_min_score = heapq.heappop(h)
        heapq.heappush(h, first_min_score + (second_min_score * 2) )
        answer += 1
    return -1

import heapq

#다른사람 풀이
'''
try except로 예외인 경우 처리해줄수 있다.
'''
def solution(scoville, k):
    heap = []
    for num in scoville:
        heapq.heappush(heap, num)
        
    mix_cnt = 0
    while heap[0] < k:
        try:
            heapq.heappush(heap, heapq.heappop(heap) + (heapq.heappop(heap) * 2))
        except IndexError:
            return -1
        mix_cnt += 1
 
    return mix_cnt
