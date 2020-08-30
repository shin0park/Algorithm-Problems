#첫번째 풀이
def dfs(k, start, visited, tickets, answer):
    answer[k] = start
    if k == len(tickets):
        return True

    for i, ticket in enumerate(tickets):
        if ticket[0] == start and not visited[i]:
            visited[i] = 1
            result = dfs(k+1, ticket[1], visited, tickets, answer)
            if result:
                return True
            visited[i] = 0
    return False
    
def solution(tickets):
    answer = [""]*(len(tickets)+1)
    visited = [0]*len(tickets)
    tickets.sort()
    dfs(0, "ICN", visited, tickets, answer)
    return answer
