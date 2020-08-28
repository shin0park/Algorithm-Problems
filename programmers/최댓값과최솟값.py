def solution(s):
    answer = ''
    num_list = list(map(int, s.split()))
    answer = str(min(num_list)) + " " + str(max(num_list))
    return answer
