# 첫번째 풀이
def solution(number, k):
    answer = ''
    collected = []
    result_len = len(number) - k
    for num in number:
        i = len(collected) - 1
        flag = False
        while k > 0 and i >= 0:
            if collected[i] < num:
                i -= 1
                k -= 1
                flag = True
            else:
                break
        if flag:
            i += 1
            collected = collected[0:i]
        collected.append(num)

    if len(collected) > result_len:
        collected = collected[0:result_len]
    return ''.join(collected)

#10번 시간초과 풀이
def solution(number, k):
    answer = ''
    pivot = 0
    selected_num = len(number) - k
    while selected_num > 0:
        temp = number[pivot : k + pivot + 1]
        temp_max = max(temp)
        max_index = pivot + temp.index(temp_max)
        k -= (max_index - pivot)
        pivot = max_index + 1
        answer += temp_max
        selected_num -= 1

    return answer

# 8, 10 번 시간초과 풀이
def solution(number, k):
    num_list = []
    for num in number:
        num_list.append(num)
    i = 0
    while k > 0:
        if i == len(num_list) - 1 or num_list[i] < num_list[i+1]:
            del num_list[i]
            k -= 1
            i = 0
        else:
            i += 1
    return ''.join(num_list)
