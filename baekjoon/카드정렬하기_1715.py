import heapq
n = int(input())
num = []
for _ in range(n):
    heapq.heappush(num, int(input()))
answer = 0
while len(num) != 1:
    min1 = heapq.heappop(num)
    min2 = heapq.heappop(num)
    sum_num = min1 + min2
    answer += sum_num
    heapq.heappush(num, sum_num)
    
print(answer)
    

    
    
