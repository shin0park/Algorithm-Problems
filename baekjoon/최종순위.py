from collections import deque
test = int(input())
while test:
    test -= 1
    n = int(input())
    team = list(map(int, input().split()))
    graph = [[False] * (n + 1) for _ in range(n + 1)]
    indegree = [0] * (n + 1)
    for i in range(n):
        start = team[i]
        indegree[start] = i
        for j in range(i + 1, n):
            graph[start][team[j]] = True

    m = int(input())
    for _ in range(m):
        a, b = map(int, input().split())
        if graph[a][b]:
            graph[a][b] = False
            graph[b][a] = True
            indegree[a] += 1
            indegree[b] -= 1
        else:
            graph[a][b] = True
            graph[b][a] = False
            indegree[a] -= 1
            indegree[b] += 1
    result = []
    q = deque([])
    for i in range(1, n + 1):
        if indegree[i] == 0:
            q.append(i)
    is_vaild = "True"
    for _ in range(n):
        if len(q) > 1:
            is_vaild = "?"
            break
        elif len(q) == 0:
            is_vaild = "IMPOSSIBLE"
            break
        now_team = q.popleft()
        result.append(now_team)
        for i in range(1, n + 1):
            if graph[now_team][i]:
                graph[now_team][i] = False
                indegree[i] -= 1
                if indegree[i] == 0:
                    q.append(i)

    if is_vaild == "True":
        for i in result:
            print(i, end=' ')
        print()
    else:
        print(is_vaild)





