def solution(participant, completion):
    answer = ''
    dict = {}
    for com in completion:
        if com in dict:
            dict[com] += 1
        else:
            dict[com] = 1
    for part in participant:
        if not(part in dict) or dict[part] == 0:
            answer = part
            break
        else:
            dict[part] -= 1
    return answer
