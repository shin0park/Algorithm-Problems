#첫번째 풀이

def solution(distance, rocks, n):
    answer = 0
    start, end = 0, distance
    rocks.append(distance)
    rocks.sort()
    while start <= end:
        prev = 0
        min_value = distance
        remove_cnt = 0
        mid = (start + end) // 2
        for i, loc in enumerate(rocks):
            if loc - prev < mid:
                remove_cnt += 1
            else:
                min_value = min(min_value, loc - prev)
                prev = loc
    
        if n < remove_cnt:
            end = mid - 1
        else:
            answer = max(answer, mid)
            start = mid + 1
    return answer

#두번째 풀이

def solution(distance, rocks, n):
    answer = 0
    start, end = 0, distance
    rocks.append(distance)
    rocks.sort()
    while start <= end:
        prev = 0
        min_value = distance
        remove_cnt = 0
        mid = (start + end) // 2
        for i, loc in enumerate(rocks):
            if loc - prev < mid:
                remove_cnt += 1
            else:
                min_value = min(min_value, loc - prev)
                prev = loc
    
        if n < remove_cnt:
            end = mid - 1
        else:
            #어차피 이부분은 mid값이 증가하는 경우 밖에 없으므로 max를 안해도 된다.
            answer = mid 
            start = mid + 1
    return answer
