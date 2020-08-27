def solution(s):
    answer = True
    stack = []
    for bracket in s:
        if bracket == '(':
            stack.append('(')
        else:
            if not stack:
                return False
            stack.pop()
    if stack:
        return False
    return True
