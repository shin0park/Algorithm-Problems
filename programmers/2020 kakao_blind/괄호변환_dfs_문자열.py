#첫번째 풀이

def balanced_string(p):# u,v로 분리
    cnt = 0
    u = ''
    v =''
    for i, c in enumerate(p):
        if c == '(':
            cnt += 1
            u += '('
        else:
            cnt -= 1
            u += ')'
        if cnt == 0:
            v = p[i+1:]
            break
    return (u, v)

def check_proper(p): #올바른 괄호 문자열인지 체크
    stack = []
    for c in p:
        if c == '(':
            stack.append('(')
        else:
            if not stack:
                return False
            stack.pop()
    if not stack:
        return True
    else:
        return False

def solution(p):
    answer = ''
    if p == '' or check_proper(p):
        return p
    u, v = balanced_string(p)
    if check_proper(u): #올바른 괄호 문자열
        answer += u #그대로 두고
        answer += solution(v) #v에 대해 재귀적
    else: #u가 올바른 괄호 문자열 아닐때
        v_result = solution(v) #v는 재귀적
        u = u[1:-1] #앞뒤 삭제
        new_u = ''# 방향 뒤집기
        for c in u:
            if c == '(':
                new_u += ')'
            else:
                new_u += '('
        answer += ('(' + v_result + ')' + new_u)
    return answer


#두번째 풀이
def balanced_string(p):# u,v로 분리
    cnt = 0
    u = ''
    v =''
    for i, c in enumerate(p):
        if c == '(':
            cnt += 1
            u += '('
        else:
            cnt -= 1
            u += ')'
        if cnt == 0:
            v = p[i+1:]
            break
    return (u, v)

'''
처음 푼것과 달리 stack(리스트) 안쓰고 count로만 체크할 수 있다.
'''
def check_proper(p): #올바른 괄호 문자열인지 체크
    count = 0
    for c in p:
        if c == '(':
            count += 1
        else:
            if count == 0:
                return False
            count -= 1
    if count == 0:
        return True
    else:
        return False

def solution(p):
    answer = ''
    if p == '' or check_proper(p):
        return p
    u, v = balanced_string(p)
    if check_proper(u): #올바른 괄호 문자열
        answer = u + solution(v) #첫번째 풀이와 달리 한줄로 더 깔금하게
    else: #u가 올바른 괄호 문자열 아닐때
        v_result = solution(v) #v는 재귀적
        u = u[1:-1] #앞뒤 삭제
        new_u = ''# 방향 뒤집기
        for c in u:
            if c == '(':
                new_u += ')'
            else:
                new_u += '('
        answer = ('(' + v_result + ')' + new_u)
    return answer
