#첫번째 풀이
#반복문
def solution(s):
    answer = 1
    for i in range(len(s), 0 , -1):
        for start in range(0, len(s) - i + 1):
            temp_str = s[start : start + i]
            reverse_str = temp_str[::-1]
            if reverse_str == temp_str:
                return i
    return answer

#두번째풀이
#더 간략하게
def solution(s):
    answer = 1
    for i in range(len(s), 0 , -1):
        for j in range(0, len(s) - i + 1):
            if s[j : j + i] == s[j : j + i][::-1]:
                return i
    return answer

#다른 사람 풀이
#재귀 사용 --- 시간초과. 
def longest_palindrom(s):
    return len(s) if s[::-1] == s else max(longest_palindrom(s[:-1]), longest_palindrom(s[1:]))
def solution(s):
    answer = longest_palindrom(s)
    return answer
