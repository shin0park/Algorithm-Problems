'''
이전에 회전 부분을 직접 구현했다면
deque의 rotate 함수를 사용하여 회전하는 방법도 있다.
'''
from collections import deque
gear = [deque(map(int, input())) for _ in range(4)]
k = int(input())
opers = []
for i in range(k):
    num, dir = map(int, input().split())
    opers.append([num - 1, dir])

for num, dir in opers:
    moving = []
    moving.append((num, dir))
    now_dir = dir
    # 오른쪽 검토
    for i in range(num, 3):
        if gear[i][2] != gear[i + 1][6]:
            now_dir *= -1
            moving.append((i + 1, now_dir))
        else:
            break
    now_dir = dir
    # 왼쪽으로 검토
    for i in range(num, 0, -1):
        if gear[i][6] != gear[i - 1][2]:
            now_dir *= -1
            moving.append((i - 1, now_dir))
        else:
            break
    for moving_num, moving_dir in moving:
        gear[moving_num].rotate(moving_dir)

answer = 0
score = 1
for i in range(4):
    if gear[i][0] == 1:
        answer += score
    score *= 2
print(answer)
