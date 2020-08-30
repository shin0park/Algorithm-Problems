#첫번째 풀이
'''
dfs를 사용한 풀이
범위가 8로 제한되어있었기에 가능
'''
min_value = 9
def dfs(count, current_num, N, number):
    global min_value
    next_num = 0
    if count > 8:
        return
    if current_num == number:
        min_value = min(min_value, count)
        return
    for i in range(0, 8):
        if i + count > 8:
            break
        next_num = next_num * 10 + N
        
        dfs(i + 1 + count, current_num + next_num, N, number)
        dfs(i + 1 + count, current_num - next_num, N, number)
        dfs(i + 1 + count, current_num * next_num, N, number)
        dfs(i + 1 + count, current_num // next_num, N, number)

def solution(N, number):
    global min_value
    dfs(0 , 0, N, number)
    if min_value == 9:
        return -1
    else:
        return min_value

#두번째 풀이
'''
dp로 푼 풀이 정석 풀이
'''
def solution(N, number):
    answer = 0
    possible_set = [0, [N]]
    
    for i in range(2,9):
        case_set = []
        seq_set = int(str(N)*i)
        case_set.append(seq_set)
        for i_half in range(1, i//2 + 1):
            for x in possible_set[i_half]:
                for y in possible_set[i-i_half]:
                    case_set.append(x + y)
                    case_set.append(x - y)
                    case_set.append(y - x)
                    case_set.append(x * y)
                    if x != 0:
                        case_set.append(y // x)
                    if y != 0:
                        case_set.append(x // y)
            if number in case_set:
                return i
            possible_set.append(case_set)
    return -1
