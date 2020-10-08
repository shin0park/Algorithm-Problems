'''
[1,2,3,4] 2개 순열
'''
import copy
date = [1,2,3,4]
k = 2
n = 4
check = [0] * n
arr = [0] * k
def dfs(inx, date, k, result):
    if inx >= k:
        result.append(copy.deepcopy(arr))
        return
    for i in range(n):
        if check[i]:
            continue
        arr[inx] = date[i]
        check[i] = 1
        dfs(inx + 1, date, k, result)
        check[i] = 0

def my_permutation(date, k):
    result = []
    dfs(0, date, k, result)
    return result

for com in my_permutation(date, k):
    print(com)

