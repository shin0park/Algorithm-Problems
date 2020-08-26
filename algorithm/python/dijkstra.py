'''
입력값

6 11
1
1 2 2
1 3 5
1 4 1
2 3 3 
2 4 2
3 2 3
3 6 5
4 3 3
4 5 1
5 3 1
5 6 2
'''
import heapq
import sys

input = sys.stdin.readline
INF = int(1e9)
#무한을의미하는 값으로 10억을 설정 10억의 경우 실수로 처리하므로 int형으로 변환해준다.

#노드 간선 개수 입력받기
n, m = map(int, input().split())
#시작 노드 입력받기
start = int(input())
#각 노드에 연결되어 있는 노드에 대한 정보를 담는 리스트 만들기
graph = [[] for _ in range(n+1)]
#최단거리 모두 무한으로 초기화
distance= [INF] * (n + 1)

#모든 간선 정보를 입력받기
for _ in range(m):
    a,b,c = map(int, input().split())
    graph[a].append((b,c))

def dijkstra(start):
    q = []
    #시작 노드로 가기 위한 최단경로는 0으로 설정하여 큐에 삽입
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:#큐가 비어있지 않으면
        #가장 최단거리가 짧은 노드에 대한 정보 꺼내기
        dist, now  = heapq.heappop(q)
        #현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if distance[now] < dist:
            continue
        #현재 노드와 연결된 다른 인접한 노드들을 확인
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(start)

for i in range(1, n+1):
    if distance[i] == INF:
        print("INFINITY")
    else:
        print(distance[i])

