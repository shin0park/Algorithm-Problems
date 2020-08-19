#첫번째 풀이
import heapq

def solution(jobs):
    answer = 0
    jobs.sort()
    num_jobs = len(jobs)
    checked = [0]* num_jobs
    waiting = []
    cnt = 0;
    start, end = 0, 0

    while cnt < num_jobs:
        for i in range(len(jobs)):
            if checked[i] == 1:
                continue
            start = jobs[i][0]
            time = jobs[i][1]
            if start < end:
                heapq.heappush(waiting, [time, start])
                checked[i] = 1
            else:
                if len(waiting) != 0:
                    if waiting[0][1] == start:
                        heapq.heappush(waiting, [time, start])
                        checked[i] = 1
                        continue
                    else:
                        break
                else:
                    heapq.heappush(waiting, [time, start])
                    checked[i] = 1
                    
        time, start = heapq.heappop(waiting)
        if start > end:
            end = start + time
        else:
            end = end + time
        answer += (end - start)
        cnt += 1

    return answer // num_jobs

#다른사람 풀이
'''
걸리는 시간을 쪼개서 더해줄수 있다
'''
import heapq
def solution(jobs):
    n = len(jobs)
    time, end, queue = 0, -1, []
    # 처리한 프로세스 개수
    count = 0
    
    answer = 0
    while count < n:
        for i in jobs:
          # i[0] = 프로세스 입력 시간, i[1] = 프로세스 끝날 때까지 걸리는 시간
            if end <i[0] <= time:
                # 현재 시간 기준, 프로세스가 queue에 들어가서 얼마나 기다렸는지.
                answer += (time - i[0])
                heapq.heappush(queue, i[1])
        if len(queue) > 0:
            # 가장 빨리 끝나는 프로세스가 끝날 때까지는 queue에 있는 프로세스 전부 대기시간이므로 값을 추가한다.
            answer += len(queue) * queue[0]
            # 끝난 시간
            end = time
            # 가장 빨리 끝나는 프로세스가 걸린 시간을 더해준다
            time += heapq.heappop(queue)
            # 프로세스가 끝났으므로 count + 1 해준다.
            count += 1
        else:
          # queue에 아직 아무것도 없으므로 시간을 +1 해준다.
            time += 1
            
    return (int(answer / n))

#다른사람 풀이
'''
heap안 쓰고 sort로만 푼 풀이
'''
def solution(jobs):
    answer = 0
    start = 0  # 현재까지 진행된 작업 시간
    length = len(jobs)

    jobs = sorted(jobs, key=lambda x: x[1])  # 소요시간 우선 정렬

    while len(jobs) != 0:
        for i in range(len(jobs)):
            if jobs[i][0] <= start:
                start += jobs[i][1]
                answer += start - jobs[i][0]
                jobs.pop(i)
                break
            # 해당시점에 아직 작업이 들어오지 않았으면 시간 ++
            if i == len(jobs) - 1:
                start += 1

    return answer // length
