#첫번째 풀이

def solution(n, lost, reserve):
    check = [1] * n
    temp = lost[:]
    for r in reserve:
        check[r-1] = 2
    for l in lost:
        if check[l-1] == 2:
            check[l-1] = 1
            temp.remove(l)
    lost = temp[:]
    lost_cnt = len(lost)
    for l in lost:
        if l - 2 >= 0 and check[l-2] == 2:
            check[l-2] = 1
            lost_cnt -= 1
        elif l < n and check[l] == 2:
            check[l] = 1
            lost_cnt -= 1
    answer = n - lost_cnt
    return answer
