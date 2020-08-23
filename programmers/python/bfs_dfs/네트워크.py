def solution(n, computers):
    answer = 0
    visited = [0]*n
    
    def dfs(node):
        visited[node] = True
        for i in range(n):
            if computers[node][i] and not visited[i]:
                dfs(i)
                
    for i in range(n):
        if not visited[i]:
            dfs(i)
            answer += 1
    return answer
