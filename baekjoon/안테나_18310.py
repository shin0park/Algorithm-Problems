n = int(input())
home = list(map(int, input().split()))
home.sort()
if len(home) % 2 == 0:
    mid = len(home) // 2
else:
    mid = len(home) // 2 + 1
print(home[mid-1])

    

    
    
