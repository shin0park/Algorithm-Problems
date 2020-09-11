#첫번째 풀이
'''
set없이 풀이
'''
def make_multiset(str):
    str = str.upper()
    result = []
    for i in range(len(str) - 1):
        temp = str[i: i+2]
        if temp.isalpha():
            result.append(temp)
    result.sort()
    return list(result)

def solution(str1, str2):
    answer = 0
    multi_str1 = make_multiset(str1)
    multi_str2 = make_multiset(str2)
    union = 0
    inters = 0
    index = 0
    while index < len(multi_str1):
        #중복
        s = multi_str1[index]
        if s in multi_str2:
            cnt_str1 = multi_str1.count(s)
            cnt_str2 = multi_str2.count(s)
            union += max(cnt_str1, cnt_str2)
            inters += min(cnt_str1, cnt_str2)
            index += cnt_str1
        else:
            union += 1
            index += 1
    for s2 in multi_str2:
        if s2 not in multi_str1:
            union += 1
    if union == 0:
        answer = 65536
    else:
        answer = int((inters / union) * 65536)
    return answer


#두번째 풀이
'''
set있이 풀이
'''
def make_multiset(str):
    str = str.upper()
    result = []
    for i in range(len(str) - 1):
        temp = str[i: i+2]
        if temp.isalpha():
            result.append(temp)
    return result

def solution(str1, str2):
    answer = 0
    multi_str1 = make_multiset(str1)
    multi_str2 = make_multiset(str2)  
    union = set(multi_str1) | set(multi_str2)
    inters = set(multi_str1) & set(multi_str2)
    
    union_sum = sum([ max(multi_str1.count(s), multi_str2.count(s)) for s in union ])
    inters_sum = sum([ min(multi_str1.count(s), multi_str2.count(s)) for s in inters ])
    
    if union_sum == 0:
        answer = 65536
    else:
        answer = int((inters_sum / union_sum) * 65536)
    return answer
