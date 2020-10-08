n = int(input())
score_list = [list(input().split()) for _ in range(n)]
answer = sorted(score_list, key = lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))
for i in range(n):
    print(answer[i][0])