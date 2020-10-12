gear_list = [list(map(int, input())) for _ in range(4)]
k = int(input())
rotate_list = []
for i in range(k):
    num, dir = map(int, input().split())
    rotate_list.append([num - 1, dir])


def rotate_gear(gear, direct):
    if direct == 1:
        temp = gear[-1]
        for i in range(7, 0, -1):
            gear[i] = gear[i - 1]
        gear[0] = temp
        return gear
    else:
        temp = gear[0]
        for i in range(0, 7):
            gear[i] = gear[i + 1]
        gear[-1] = temp
        return gear


for num, dir in rotate_list:
    moving = []
    moving.append((num, dir))
    now_dir = dir
    # 오른쪽 검토
    for i in range(num, 3):
        if gear_list[i][2] != gear_list[i + 1][6]:
            now_dir *= -1
            moving.append((i + 1, now_dir))
        else:
            break
    now_dir = dir
    # 왼쪽으로 검토
    for i in range(num, 0, -1):
        if gear_list[i][6] != gear_list[i - 1][2]:
            now_dir *= -1
            moving.append((i - 1, now_dir))
        else:
            break
    for moving_num, moving_dir in moving:
        gear_list[moving_num] = rotate_gear(gear_list[moving_num], moving_dir)

answer = 0
score = 1
for i in range(4):
    if gear_list[i][0] == 1:
        answer += score
    score *= 2
print(answer)
