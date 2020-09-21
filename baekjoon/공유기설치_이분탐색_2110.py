n, c = map(int, input().split())
home = [int(input()) for _ in range(n)]
home.sort()
start = 1
end = home[-1] - home[0]
max_value = 0

while start <= end:
    mid = (start + end) // 2
    value = home[0]
    cnt = 1
    for i in range(1, n): 
        if home[i] - value >= mid:
            value = home[i]
            cnt += 1
            if cnt >= c:
                break
    if cnt >= c:
        start = mid + 1
        max_value = max(max_value, mid)
    else:
        end = mid - 1

print(max_value)   

    
    
