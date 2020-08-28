#첫번째 풀이
'''
dp로 각각 배열에 이 지점까지 도착하기 위한 최대값을 저장하여 차례대로 나아가서 정답을 찾는다.
'''
def solution(land):
    answer = 0
    d = [[0] * 4 for _ in range(len(land))]
    for i in range(4):
        d[0][i] = land[0][i]
    for c in range(1, len(land)):
        for i in range(4):
            for j in range(4):
                if i == j:
                    continue
                d[c][i] = max(d[c][i], d[c-1][j])
            d[c][i] = d[c][i] + land[c][i] 
    return max(d[len(land)-1])


#두번째 풀이
'''
더 간략한 코드
따로 d라는 배열만들지 말고 입력받은 land배열의 값을 수정해 나가면 된다.
'''
def solution(land):
    answer = 0
    size = len(land)
    for i in range(1, size):
        for j in range(4):
            land[i][j] += max(land[i - 1][:j] + land[i - 1][j + 1:])
    return max(land[size - 1])
