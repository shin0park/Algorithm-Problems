#첫번째 풀이

def solution(brown, yellow):
    answer = []
    for i in range(1, int(yellow ** (1/2)) + 1):
        if yellow % i == 0:
            j = int(yellow / i)
            if (2 * (i + j) + 4) == brown:
                answer = [i + 2, j + 2]
                answer.sort(reverse = True)
                return answer
    return answer
