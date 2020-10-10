import copy
r, c, k = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(3)]

def sorting(lst):
    dict = {}
    for i in lst:
        if i == 0:
            continue
        if dict.get(i) == None:
            dict[i] = 1
        else:
            dict[i] += 1
    new_lst = []
    for k, v in dict.items():
        new_lst.append([v, k])
    new_lst.sort()
    result = []
    for cnt, num in new_lst:
        result += [num, cnt]
    #행이나 열의 크기가 100 넘어가는 경우 나머지 버린다
    if len(result) > 100:
        result = result[:100]
    return result

def make_matrix(arr, m):
    new_arr = [[0] * m for _ in range(len(arr))]
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            new_arr[i][j] = arr[i][j]
    return new_arr

def rotate_90(arr):
    n = len(arr)
    m = len(arr[0])
    new_arr = [[0] * n for _ in range(m)]
    for i in range(m):
        for j in range(n):
            new_arr[i][j] = arr[j][i]
    return new_arr

is_vaild = False
time = 0
while time <= 100:
    if len(arr) >= r and len(arr[0]) >= c and arr[r-1][c-1] == k:
        is_vaild = True
        break
    time += 1
    row_len = len(arr)
    col_len = len(arr[0])
    #r연산
    if row_len >= col_len:
        temp = []
        max_len = 0
        for i in range(row_len):
            sorting_result = sorting(arr[i])
            max_len = max(max_len, len(sorting_result))
            temp.append(sorting_result)
        arr = copy.deepcopy(make_matrix(temp, max_len))
    #c연산
    else:
        arr = rotate_90(arr)
        temp = []
        max_len = 0
        for i in range(col_len):
            sorting_result = sorting(arr[i])
            max_len = max(max_len, len(sorting_result))
            temp.append(sorting_result)
        arr = copy.deepcopy(make_matrix(temp, max_len))
        arr = copy.deepcopy(rotate_90(arr))

if not is_vaild:
    print(-1)
else:
    print(time)