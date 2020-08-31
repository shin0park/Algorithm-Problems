#첫번째 풀이

from collections import deque
def solution(s):
    answer = len(s)
    for i in range(1, len(s) + 1):
        short_str = ""
        start = 0
        q = deque()
        for start in range(0, len(s), i):
            temp = s[start: start + i]
            q.append(temp)
        pre = q.popleft()
        cnt = 1
        while q:
            now = q.popleft()
            if pre == now:
                cnt += 1
            else:
                if cnt == 1:
                    short_str += pre
                else:
                	short_str += (str(cnt) + pre)
                cnt = 1
                pre = now
        if cnt == 1:
            short_str += pre
        else:
            short_str += (str(cnt) + pre)
        answer= min(answer, len(short_str))
    return answer

#두번째 풀이
'''
꼭 큐를 사용하지 않아도 된다.
'''
def solution(s):
    answer = len(s)
    # 문자열길이의 반개 단위로도 안된다면 최대는 처음의 상태일 수 밖에 없다.
    for i in range(1, len(s) // 2 + 1):
        short_str = ""
        start = 0
        cnt = 1
        pre = s[:i]
        for start in range(i, len(s), i):
            now = s[start: start + i]
            if now == pre:
                cnt += 1
            else:
                if cnt == 1:
                    short_str += pre
                else:
                	short_str += (str(cnt) + pre)
                cnt = 1
                pre = now
        if cnt == 1:
            short_str += pre
        else:
            short_str += (str(cnt) + pre)
        answer= min(answer, len(short_str))
    return answer

#세번째 풀이
'''
파이썬 문법을 활용하여 코드를 한줄로 줄일수 있다.
'''
def solution(s):
    answer = len(s)
    for i in range(1, len(s) // 2 + 1):
        short_str = ""
        start = 0
        cnt = 1
        pre = s[:i]
        for start in range(i, len(s), i):
            now = s[start: start + i]
            if now == pre:
                cnt += 1
            else:
                short_str += (str(cnt) + pre) if cnt >= 2 else pre #한줄코드
                cnt = 1
                pre = now
        short_str += (str(cnt) + pre) if cnt >= 2 else pre #한줄 코
        answer= min(answer, len(short_str))
    return answer
