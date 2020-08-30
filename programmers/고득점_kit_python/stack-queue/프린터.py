#첫번째 풀이
def solution(priorities, location):
    answer = 0
    indexQueue = []
    for i in range(len(priorities)):
        indexQueue.append(i)

    while priorities:
        maxValue = max(priorities)
        tempValue = priorities.pop(0)
        tempIndex = indexQueue.pop(0)

        if tempValue < maxValue:
            priorities.append(tempValue)
            indexQueue.append(tempIndex)
        else:
            answer += 1
            if tempIndex == location:
                return answer      
    return answer

#두번째 풀이
"""
enumerate
반복문 사용 시 몇 번째 반복문인지 확인할 수 있다.
인덱스 번호와 컬렉션의 원소를 tuple형태로 반환한다.
튜플의 각각의 값의 max값 구할 수 있다.
"""
def solution(priorities, location):
    answer = 0
    q = [(v,i) for i,v in enumerate(priorities)]
    
    while q:
        maxValue = max(q)[0]
        temp = q.pop(0)
        if temp[0] < maxValue:
            q.append(temp)
        else:
            answer += 1
            if temp[1] == location:
                return answer    
        
    return answer

#세번째 풀이
##리스트를 queue처럼 사용하여 pop(0)할 경우 한칸씩 왼쪽으로 이동해야하므로
##pop하는데 더많은 복잡도가 발생한다
##deque로 popleft하는 것이 더 효율적이다.
from collections import deque
def solution(priorities, location):
    answer = 0
    q = deque([(v,i) for i,v in enumerate(priorities)])
    
    while q:
        maxValue = max(q)[0]
        temp = q.popleft()
        if temp[0] < maxValue:
            q.append(temp)
        else:
            answer += 1
            if temp[1] == location:
                return answer    
        
    return answer

#튜플이 아닌 리스트로 구현할 경우
from collections import deque
def solution(priorities, location):
    answer = 0
    q = deque([[priorities[i], i] for i in range(len(priorities))])

    while q:
        maxValue = max(q)[0]
        temp = q.popleft()
        if temp[0] < maxValue:
            q.append(temp)
        else:
            answer += 1
            if temp[1] == location:
                return answer    
        
    return answer

#다른사람 풀이
'''
실제 그 값을 삭제하지 않고 0을 대입하여 무효화 시키는 방법도 있다.
문제 상에서의 액션그대로 구현하지 않고 cursor를 증가시켜 나머지로
컨트롤 하는 것처럼 눈속임 가능 - 더 시간적으로 효율적이다
'''
def solution(priorities, location):
    jobs = len(priorities)
    answer = 0
    cursor = 0
    while True:
        if max(priorities) == priorities[cursor%jobs]:
            priorities[cursor%jobs] = 0
            answer += 1
            if cursor%jobs == location:
                break
        cursor += 1   
    return answer
