'''
[1,2,3,4] 2개 순열
'''
data = [1,2,3,4]
k = 2
def my_permutaion(arr, r):
    for i in range(len(arr)):
        if r == 1:
            yield [arr[i]]
        else:
            for next in my_permutaion(arr, r-1):
                yield [arr[i]] + next

for per in my_permutaion(data, k):
    print(per)