data = input()
count = [0,0]
#count[0] 0으로 만드는 경우
#count[1] 1으로 만드는 경우

for i in range(len(data)):
  if i == len(data)-1 or data[i] != data[i+1]:
    if data[i] == '1':#1일때
      count[0] += 1
    else:
      count[1] += 1

print(min(count))
