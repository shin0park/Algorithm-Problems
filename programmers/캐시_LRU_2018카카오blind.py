#첫번째 풀이
'''
페이지 교체 알고리즘 - LRU에 대한 이해가 필요하다.
cache에 해당 데이터가 있을 경우
- 그 데이터의 위치를 찾아 삭제하고 cache에 새로 넣어주어 update한다.
cache에 해당 데이터가 없을 경우
- cache가 다 차지 않았다면 데이터를 cache에 추가만 해주면된다.
- 만약 다 차있다면 가장 오래된 데이터를 삭제하고 cache에 데이터를 추가해주면된다.

다만 주의해야될것은 cacheSize가 0일때는 계속 cache miss가 발생하므로 따로 처리해줘야한다.
'''
from collections import deque
def solution(cacheSize, cities):
    answer = 0
    if cacheSize == 0:
        return len(cities) * 5
    cities = [c.upper() for c in cities]
    cache = deque([])
    for city in cities:
        #city가 cache에 있는지 없는지에 따라 동작방식이 다르다.
        if not city in cache:
            if len(cache) < cacheSize:
                cache.append(city)
            else:
                cache.popleft()
                cache.append(city)
            answer += 5
        else:
            del cache[cache.index(city)]
            cache.append(city)
            answer += 1
    return answer
