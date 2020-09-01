#첫번째 풀이

def solution(N, stages):
    answer = []
    state = [[0,0] for _ in range(N + 2)]
    fail_list = []
    for stage in stages:
        state[stage][0] += 1
        for i in range(1, stage + 1):
            state[i][1] +=1

    for i in range(1, N + 1):
        if state[i][1] == 0:
            fail = 0
        else:
            fail = state[i][0] / state[i][1]
        fail_list.append([i, fail])
        
    fail_sort = sorted(fail_list, key = lambda x: x[1], reverse = True)

    for i in range(N):
        answer.append(fail_sort[i][0])
    return answer

#두번째 풀이
'''
입력받은 stages 원소마다 각각 계산해준 첫번째 풀이보다
python의 count 함수를 사용하여 각각 스테이지의 실패율을 계산하는것이
더 깔끔하고 효율적이다.
'''
def solution(N, stages):
    answer = []
    length = len(stages)
    
    for i in range(1, N + 1):
        count = stages.count(i) # i에 머물러 있는 사람 수 
        #실패율 계산
        if length == 0:
            fail = 0
        else:
            fail = count / length
        answer.append([i, fail])
        length -= count
    # 실패율 기준으로 sorting 이미 스테이지 순은 나열되어 있는 상태이므로
    answer = sorted(answer, key = lambda x: x[1], reverse = True)
    answer = [i[0] for i in answer]
    return answer
