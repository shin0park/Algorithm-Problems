#첫번째 풀이
'''
최대공약수 만큼 대각선이 점을 지나간다.
최대공약수가 g라면 대각선이 지나가는 정사각형의 개수는 
g*((w//g) + (h // g) - 1)이므로
결국 w + h - g이다.
'''
def gcd(a,b):
    while b != 0:
        a, b = b, a % b
    return a

def solution(w,h):
    answer = 1
    big = max(w,h)
    small = min(w,h)
    g = gcd(big, small)
    answer = w * h - (w + h - g)
    return answer

#두번째 풀이
'''
math에 최대공약수 구하는 라이브러리 gcd가 있다.
'''
import math
def solution(w,h):
    answer = 1
    g = math.gcd(w, h)
    answer = w * h - (w + h - g)
    return answer
