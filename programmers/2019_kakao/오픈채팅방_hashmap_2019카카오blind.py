#첫번째 풀이
'''
dictionary used
'''
def solution(record):
    answer = []
    action = []
    name = {}
    for re in record:
        re_list = re.split(" ")
        if re_list[0] == "Enter" or re_list[0] == "Change":
            name[re_list[1]] = re_list[2]
        if re_list[0] == "Enter" or re_list[0] == "Leave":
            action.append([re_list[0], re_list[1]])
    for act in action:
        if act[0] == 'Enter':
            answer.append(name[act[1]]+"님이 들어왔습니다.")
        else:
            answer.append(name[act[1]]+"님이 나갔습니다.")
    return answer
