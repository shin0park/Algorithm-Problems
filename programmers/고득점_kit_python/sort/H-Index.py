#첫번째 풀이
def solution(citations):
    answer = 0
    citations.sort()
    paper_num = len(citations)
    h = citations[-1]
    while h:
        for i in range(len(citations)):
            if citations[i] >= h:
                index = i
                break
        if (paper_num - index) >= h and (index <= h):
            return h
        h -= 1
    return answer

#두번째 풀이

def solution(citations):
    citations = sorted(citations)
    l = len(citations)
    for i in range(l):
        if citations[i] >= l-i:
            return l-i
    return 0
