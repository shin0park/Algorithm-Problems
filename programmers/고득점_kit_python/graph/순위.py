#첫번째 풀이

def solution(n, results):
    answer = 0
    win = []
    lose = []
    for i in range(0, n+1):
        win.append(set())
        lose.append(set())
    
    for i in range(1, n+1):
        for result in results:
            if result[0] == i: # i가 이겼을떄
                lose[i].add(result[1]) #i에게 진사람들
            elif result[1] == i: #i 가 졌을때
                win[i].add(result[0]) #i를 이긴사람들
        # i에게 진시람들은 모두 i를 이긴사람의 진사람이다.        
        for winner in win[i]: 
            lose[winner].update(lose[i])
        # i를 이긴사람들은 i에게 진사람들의 이긴사람이다.
        for loser in lose[i]: 
            win[loser].update(win[i])
    #만약 i를 기준으로 이긴사람과 진사람의 합이 n-1이면 순위를 알수 있다.      
    for i in range(1, n + 1): 
        if len(win[i]) + len(lose[i]) == n-1:
            answer += 1
    return answer

# 두번째 풀이
'''
dictionary에 set을 넣을 수 있따.
key를 인덱스처럼 숫자의 값을 갖으면 된다.
'''
def solution(n, results):
    answer = 0
    ####
    win = {}
    lose = {}
    for i in range(1, n+1):
        win[i], lose[i] = set(), set()
    ####
    for i in range(1, n+1):
        for result in results:
            if result[0] == i: # i가 이겼을떄
                lose[i].add(result[1]) #i에게 진사람들
            elif result[1] == i: #i 가 졌을때
                win[i].add(result[0]) #i를 이긴사람들
                
        for winner in win[i]: # i에게 진시람들은 모두 i를 이긴사람의 진사람이다.
            lose[winner].update(lose[i])
        for loser in lose[i]: # i를 이긴사람들은 i에게 진사람들의 이긴사람이다.
            win[loser].update(win[i])
    for i in range(1, n + 1): #만약 i를 기준으로 이긴사람과 진사람의 합이 n-1이면 순위를 알수 있다.
        if len(win[i]) + len(lose[i]) == n-1:
            answer += 1
    return answer
