#첫번째 풀이
from functools import cmp_to_key
def comparator(a,b):
    t1 = a + b
    t2 = b + a
    return (t1 > t2) - (t1 < t2) 

def solution(numbers):
    answer = ''
    str_num = [str(x) for x in numbers]
    str_num = sorted(str_num, key = cmp_to_key(comparator), reverse = True)
    for s in str_num:
        answer += s
    answer = str(int(answer))
    return answer

#다른사람 풀이
import functools

def comparator(a,b):
    t1 = a+b
    t2 = b+a
    return (int(t1) > int(t2)) - (int(t1) < int(t2)) #  t1이 크다면 1  // t2가 크다면 -1  //  같으면 0

def solution(numbers):
    n = [str(x) for x in numbers]
    n = sorted(n, key=functools.cmp_to_key(comparator),reverse=True)
    answer = str(int(''.join(n)))
    return answer
