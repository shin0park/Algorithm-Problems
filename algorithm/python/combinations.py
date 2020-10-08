'''
[1,2,3,4] 2개 조합
'''
data = [1,2,3,4]
k = 2

def my_combination(arr, r):
    for i in range(len(arr)):
        if r == 1:
            yield [arr[i]]
        else:
            for next in my_combination(arr[i + 1:], r-1):
                yield [arr[i]] + next

for com in my_combination(data, k):
    print(com)