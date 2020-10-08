'''
[1,2,3,4] 2개 중복순
'''
import copy
date = [1,2,3,4]
k = 2
n = 4
arr = [0] * k
def dfs(inx, date, k, result):
    if inx >= k:
        result.append(copy.deepcopy(arr))
        return
    for i in range(n):
        arr[inx] = date[i]
        dfs(inx + 1, date, k, result)

def my_permutation(date, k):
    result = []
    dfs(0, date, k, result)
    return result

for com in my_permutation(date, k):
    print(com)

