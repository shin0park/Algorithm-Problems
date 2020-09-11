#첫번째 풀이
def solution(dartResult):
    answer = 0
    value_list = []
    num = 0
    index = -1
    for i, result in enumerate(dartResult):
        if result.isdigit():
            index += 1
            num = int(result)
            if num == 0:
                if dartResult[i - 1].isdigit():
                    num = 10
        else:
            if result == 'S':
                value_list.append(num ** 1)
            elif result == 'D':
                value_list.append(num ** 2)
            elif result == 'T':
                value_list.append(num ** 3)
            elif result == '*':
                value_list[index] *= 2
                if index != 0:
                    value_list[index - 1] *= 2
            else:
                value_list[index] *= (-1)
    answer = sum(value_list)         
    return answer


#두번째 풀이
'''
dict로 값을 지정해줘서 더 깔끔한 코드로
'''
def solution(dartResult):
    answer = 0
    area = {'S': 1, 'D': 2, 'T': 3}
    value_list = []
    num = 0
    index = -1
    for i, result in enumerate(dartResult):
        if result.isdigit():
            index += 1
            num = int(result)
            if num == 0:
                if dartResult[i - 1].isdigit():
                    num = 10
        else:
            if result == '*':
                value_list[index] *= 2
                if index != 0:
                    value_list[index - 1] *= 2
            elif result == '#':
                value_list[index] *= (-1)
            else:
                value_list.append(num ** area[result])
    answer = sum(value_list)         
    return answer
