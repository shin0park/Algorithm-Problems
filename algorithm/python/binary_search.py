import sys

def binary_search(array, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        #중간점 인덱스 반환
        
        if array[mid] == target:
            return mid
        #중간점 값보다 찾고자 하는 값이 클 경우 오른쪽 확인
        elif array[mid] < target:
            start = mid + 1
        #중간점 값보다 찾고자 하는 값이 작을 경우 왼쪽 확인
        else:
            end = mid - 1

    return None #못찾을 경우


if __name__ == "__main__":
    #입력받기
    #원소의 개수와 찾고자하는 값
    n, target = list(map(int, input().split()))
    #전체원소 입력받기
    array = list(map(int, input().split()))
    
    #sys로 입력받기
    #n , target = map(int, sys.stdin.readline().rstrip().split())
    #array = list(map(int, sys.stdin.readline().rstrip().split()))
    
    #이진탐색 수행 결과 출력
    result = binary_search(array, target, 0, n-1)
    if result == None:
        print("원소가 존재하지 않습니다.")
    else:
        print(result + 1)

