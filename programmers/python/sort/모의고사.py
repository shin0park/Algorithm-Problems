#첫번째 풀이

def solution(answers):
    answer = []
    score = [0,0,0]
    one = [i for i in range(1,6)]
    two = [2, 1, 2, 3, 2, 4, 2, 5]
    three = [ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    people = [one,two,three]
    num = 0
    for ans in answers:
        for i in range(3):
            if ans == people[i][num % len(people[i])]:
                score[i] += 1
        num += 1
    maxValue = max(score)
    for i in range(3):
        if maxValue == score[i]:
            answer.append(i+1)
    return answer

#두번째 풀이
'''
enumerate으로 더 깔끔한 코드 가능.
'''
def solution(answers):
    answer = []
    score = [0,0,0]
    one = [i for i in range(1,6)]
    two = [2, 1, 2, 3, 2, 4, 2, 5]
    three = [ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    people = [one,two,three]
    
    for num, ans in enumerate(answers):
        for i in range(3):
            if ans == people[i][num % len(people[i])]:
                score[i] += 1
                
    maxValue = max(score)
    for i in range(3):
        if maxValue == score[i]:
            answer.append(i+1)
    return answer
