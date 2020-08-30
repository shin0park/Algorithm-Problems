#첫번째 풀이
visited = [0]*51
min_value = 987987987

def dfs(result, begin, target, words):
    global min_value 
    if begin == target:
        min_value = min(min_value, result)
        return
    for i, word in enumerate(words):
        cnt = 0
        for j, c in enumerate(word):
            if begin[j] != c:
                cnt += 1
        if cnt == 1 and not visited[i]:
            visited[i] = 1
            dfs(result + 1, word, target, words)
            visited[i] = 0
            
def solution(begin, target, words):
    global min_value 
    dfs(0, begin, target, words)
    if min_value == 987987987:
        return 0
    return min_value
