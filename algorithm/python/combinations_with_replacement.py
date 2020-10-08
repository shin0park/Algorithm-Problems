'''
[1,2,3,4] 2개 중복조합
'''
data = [1,2,3,4]
k = 2

def my_combinations_with_replacement(arr, r):
    for i in range(len(arr)):
        if r == 1:
            yield [arr[i]]
        else:
            for next in my_combinations_with_replacement(arr[i:], r-1):
                yield [arr[i]] + next

for com in my_combinations_with_replacement(data, k):
    print(com)