#첫번째 풀이
'''
문자열이 숫자인지 아닌지
 a - 문자열
 a.isdigit() 숫자
 a.isalpha() 문자
문자를 대문자로
 a.upper()
 소문자로
 a.lower()
'''
def solution(s):
    answer = ''
    pre = ' '
    for i in s:
        if pre == ' ':
            if i.isdigit():
                answer += i
            else:
                answer += i.upper()
        else:
            answer += i.lower()
        pre = i
    return answer
