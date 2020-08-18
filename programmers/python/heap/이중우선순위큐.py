#첫번째 풀이

import heapq

def solution(operations):
    answer = []
    h = []
    for operation in operations:
        oper = operation.split(" ")
        if oper[0] == 'I':
            heapq.heappush(h, int(oper[1]))
        else:
            if len(h) == 0:
                continue
            if oper[1] == '1':
                h.pop(h.index(heapq.nlargest(1,h)[0]))
            else:
                heapq.heappop(h)

    if len(h) == 0:
        return [0,0]
    else:
        return [max(h),h[0]]
    return answer
