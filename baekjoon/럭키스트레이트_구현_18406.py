num = list(map(int, input()))
n = len(num)
sum_front = sum(num[:n//2])
sum_back = sum(num[n//2:])
if sum_front == sum_back:
    print("LUCKY")
else:
    print("READY")
    

    
