'''
가장긴증가하는부분수열 문제 1의 경우에는 범위가 작아 dp로도 가능했지만 

문제 2의 경우에는 이진탐색으로 풀어야 시간초과가 아닐수 있다.

어차피 최대 길이를 찾는 것이므로 오름차순순으로 table 배열에 값을 넣어준다. 

만약 들어가야 할 자리에 값이 있다면 그대로 덮어서 써준다. 어차피 최대 길이를 찾는 것이므로
'''
import sys
import bisect
input = sys.stdin.readline
N = int(input())
arr = list(map(int, input().split()))
table = [arr[0]]
for i in range(1,N):
    if table[-1] < arr[i]:
        table.append(arr[i])
    else:
        left_index = bisect.bisect_left(table, arr[i])
        table[left_index] = arr[i]
print(len(table))
        
