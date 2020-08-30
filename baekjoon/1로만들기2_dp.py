MAX = 1000001
n =int(input())
d = [0] * MAX
before = [ 0 for i in range(MAX)]
for i in range(2, n+1):
  d[i] = d[i-1] + 1
  pre = i - 1
  if i % 3 == 0:
    if d[i] > d[i // 3] + 1:
      d[i] = d[i // 3] + 1
      pre = i // 3
    d[i] = min(d[i], d[i // 3] + 1)
  elif i % 2 == 0:
    if d[i] > d[i // 2] + 1:
      d[i] = d[i // 2] + 1
      pre = i // 2
  before[i] = pre #각 숫자마다 파생된 숫자를 저장한다.

print(d[n])
temp = n
while temp >= 1:
  print(temp, end=" ")
  temp = before[temp] #n부터 과정을 타고들어가면서 출력한다.
