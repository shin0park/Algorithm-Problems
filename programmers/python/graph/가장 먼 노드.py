#첫번째 풀이
#graph #인접리스트 #bfs
# 인접리스트를 이용해 그래프 생성 후 bfs로 각각의 최단거리 구해서 max값을 구함

from collections import deque

def solution(n, edge):
    answer = 0
    graph = [[] for _ in range(n + 1)]
    dist = [-1] * (n + 1)
    for vertex in edge:
        graph[vertex[0]].append(vertex[1])
        graph[vertex[1]].append(vertex[0])
    start = 1
    max_len = 0
    queue = deque([start])
    dist[start] = 0
    while queue:
        node = queue.popleft()
        for next_node in graph[node]:
            if dist[next_node] == -1:
                queue.append(next_node)
                dist[next_node] = dist[node] + 1
                max_len = dist[next_node]

    for node_dist in dist:
        if max_len == node_dist:
            answer += 1
    return answer

#두번째 풀이

from collections import deque

def solution(n, edge):
    answer = 0
    graph = [[] for _ in range(n + 1)]
    dist = [-1] * (n + 1)
    for (a , b) in edge: #(a,b)의 튜플로 받아서 더 깔끔한 코드로 수정
        graph[a].append(b)
        graph[b].append(a)
    start = 1
    max_len = 0
    queue = deque([start])
    dist[start] = 0
    while queue:
        node = queue.popleft()
        for next_node in graph[node]:
            if dist[next_node] == -1:
                queue.append(next_node)
                dist[next_node] = dist[node] + 1
                max_len = dist[next_node]
    
    answer = dist.count(max_len)
    #for문으로 하나씩 count증가안해도 count함수 사용하면 가능하다.

    return answer
