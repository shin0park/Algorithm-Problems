from itertools import product

min_value = int(1e9)
max_value = -int(1e9)
n = int(input())
arr = list(map(int, input().split()))
cal = ['+','-','*','%']
cal_num = list(map(int, input().split()))

def calculate(n, arr, cal_list):
    result = arr[0]
    for i in range(1, n):
        sign = cal_list[i-1]
        if sign == '+':
            result += arr[i]
        elif sign == '-':
            result -= arr[i]
        elif sign == '*':
            
            result *= arr[i]
        else:
            if result < 0:
                result = -(-result // arr[i])
            else:
                result //= arr[i]
    return result

for i in product(cal, repeat = n-1):
    is_vaild = True
    for j, num in enumerate(cal_num):
        if list(i).count(cal[j]) != num:
            is_vaild = False
            break
    if is_vaild:
        result = calculate(n, arr, i)
        max_value = max(max_value, result)
        min_value = min(min_value, result)

print(max_value)
print(min_value)

    
        
