from itertools import combinations
n = int(input())
score = [list(map(int, input().split())) for _ in range(n)]
member = [i for i in range(n)]
answer = int(1e9)
def get_score(team):
    result = 0
    for i in range(n):
        if i in team:
            for j in range(n):
                if i == j:
                    continue
                if j in team:
                    result += score[i][j]
    return result
for com in combinations(member, n//2):
    teamA = com
    teamB = []
    for i in range(n):
        if i not in teamA:
            teamB.append(i)
    scoreA = get_score(teamA)
    scoreB = get_score(teamB)
    answer = min(answer, abs(scoreA - scoreB))
print(answer)
