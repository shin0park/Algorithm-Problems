#첫번째 풀이
'''
stack 에 하나씩 쌓아나가면서 우선순위에 해당하는 연산부호가 나올경우 stack에 있는 값을 pop()하여
연산을 해준뒤 다시 stack에 넣어준다. 이렇게 한번 진행하면 하나의 연산부호에 대한 처리가 다끝난것이다.
이를 연산부호 개수만큼 똑같이 계산하면 결국 stack는 결과값 1개만 남게된다. 그값의 max값을 구해주면 끝이다.
'''
from itertools import permutations
import copy

def operation(num1, num2, op):
    if op == '+':
        return str(int(num1) + int(num2))
    if op == '-':
        return str(int(num1) - int(num2))
    if op == '*':
        return str(int(num1) * int(num2))
def solution(expression):
    answer = 0
    oper = ['*','-','+']
    oper_list = [list(cal) for cal in permutations(oper, 3)]
    stack = []
    num_str = ''
    for e in expression:
        if e.isdigit():
            num_str += e
        else:
            stack.append(num_str)
            num_str = ''
            stack.append(e)
    stack.append(num_str)
    
    max_value = 0
    for cal in oper_list:
        new_stack = copy.deepcopy(stack)
        priority = 0
        while priority < 3:
            temp = []
            for i, express in enumerate(new_stack):
                if new_stack[i-1] == cal[priority]:
                    mid = temp.pop()
                    left = temp.pop()
                    temp.append(operation(left, express, mid))
                else:
                    temp.append(express)
            new_stack = copy.deepcopy(temp)
            priority += 1
        max_value = max(max_value, abs(int(new_stack[0])))  
    return max_value
