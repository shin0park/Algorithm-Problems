#첫번째 풀이
'''
중복검사를 dict으로 함
'''
def solution(n, words):
    answer = [0,0]
    dict = {}
    pre = words[0][-1]
    dict[words[0]] = 1
    for i in range(1, len(words)):
        if pre != words[i][0]:
            answer = [i % n + 1, i // n + 1]
            break
        if words[i] in dict:
            answer = [i % n + 1, i // n + 1]
            break
        dict[words[i]] = 1
        pre = words[i][-1]
    print(dict)
    return answer

#두번째 풀이
'''
중복검사를 dict으로 하지 않고 원래 배열안에 이 값이 있는지 없는지 python에서는 in으로 확인가능하다.
굳이 따로 dict를 생성해줄 필요가 없다.
'''

def solution(n, words):
    answer = [0,0]
    pre = words[0][-1]
    for i in range(1, len(words)):
        if pre != words[i][0]:
            answer = [i % n + 1, i // n + 1]
            break
        if words[i] in words[:i]:
            answer = [i % n + 1, i // n + 1]
            break
        pre = words[i][-1]
    return answer
