def solution(clothes):
    answer = 1
    dict = {}
    for clothe in clothes:
        kinds = clothe[1]
        if kinds in dict:
            dict[kinds] += 1
        else:
            dict[kinds] = 1
    for k in dict:
        answer *= (dict[k] + 1)
    return answer - 1
