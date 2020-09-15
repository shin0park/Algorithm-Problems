from collections import deque
answer = []
n, m, k, x = map(int, input().split())
graph = [[] for _ in range(n+1)]
for i in range(m):
    start, end = map(int, input().split())
    graph[start].append(end)
dist = [-1] * (n+1)
dist[x] = 0
q = deque([])
q.append(x)
while q:
    node = q.popleft()
    for next_node in graph[node]:
        if dist[next_node] == -1:
            dist[next_node] = dist[node] + 1
            q.append(next_node)
            if dist[next_node] == k:
                answer.append(next_node)
                
answer.sort()
if not answer:
    print(-1)
else:
    for ans in answer:
        print(ans)
