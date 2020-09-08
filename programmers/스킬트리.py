#첫번째 풀이
def solution(skill, skill_trees):
    answer = 0
    for skill_tree in skill_trees:
        is_vaild = True
        pre = -1
        for st in skill_tree:
            if st in skill:
                now = skill.index(st)
                if now != pre + 1 or (pre == -1 and now != 0):
                    is_vaild = False
                    break
                pre = now
        if is_vaild:
            answer += 1
    return answer
