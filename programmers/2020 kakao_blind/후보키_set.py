#첫번째 풀이
'''
set 없이 중복 여부를 dict으로 체크해주었다.
set없이 123안에 23이 들어있는지 체크하니 for문이 더 깊어지고 
깔끔한 코드가 아니었다.
중복 체크나 집합안에 포함되는지 여부를 구할때 set을 사용하도록 하자
'''
from itertools import combinations

def check_unique(cand_key, relation):
    dict = {}
    for row in relation:
        temp = ''
        for i in cand_key:
            temp += row[i]
        if temp in dict:
            return False
        dict[temp] = 1
    return True
def solution(relation):
    answer = 0
    col_len = len(relation[0])
    index = [i for i in range(col_len)]
    cand_key_list = []
    for i in range(1, col_len + 1):
        test_key = map(list, combinations(index, i))
        for key in test_key:
            key.sort()
            is_minimal = True
            for cand_key in cand_key_list:
                cnt = 0
                for i in cand_key:
                    for j in key:
                        if i == j:
                            cnt += 1
                            break
                if cnt == len(cand_key):
                    is_minimal = False
                    break
            if not is_minimal:
                continue
            result = check_unique(key, relation)
            if result:
                cand_key_list.append(key)
    return len(cand_key_list)

#두번째 풀이
'''
set를 사용하니 123안에 23이 포함되어 있는지 포함관계를 알아볼때 더 편리했다
set의 issubset을 사용하면 된다
작은 set.issubset(더큰 set)
set의 경우 set에 다 add 한뒤 중복이 없었다면 맞는 len의 길이와 비교해줘서
중복을 확인하면 된다.
'''
from itertools import combinations

def check_unique(cand_key, relation):
    unique_set = set()
    for row in relation:
        temp = ''
        for i in cand_key:
            temp += row[i]
        unique_set.add(temp)
    if len(unique_set) != len(relation):
        return False
    return True
def solution(relation):
    answer = 0
    col_len = len(relation[0])
    index = [i for i in range(col_len)]
    cand_key_list = []
    test_key = [set(k) for i in range(1, col_len + 1) for k in combinations(index, i)]
    for key in test_key:
        is_minimal = True
        for cand_key in cand_key_list:
            if cand_key.issubset(key):
                is_minimal = False
                break
        if not is_minimal:
            continue
        result = check_unique(key, relation)
        if result:
            cand_key_list.append(key)
    return len(cand_key_list)
