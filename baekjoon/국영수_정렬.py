from functools import cmp_to_key
n= int(input())
score_list = [list(input().split()) for _ in range(n)]

def comparator(t1, t2):
    name1, name2 = t1[0], t2[0]
    ko1, en1, math1 = map(int, t1[1:])
    ko2, en2, math2 = map(int, t2[1:])
    if ko1 != ko2:
        return (ko1 < ko2) - (ko1 > ko2)
    else:
        if en1 != en2:
            return (en1 > en2) - (en1 < en2)
        else:
            if math1 != math2:
                return (math1 < math2) - (math1 > math2)
            else:
                return (name1 > name2) - (name1 < name2)
answer = sorted(score_list, key = cmp_to_key(comparator))
for i in range(n):
    print(answer[i][0])
