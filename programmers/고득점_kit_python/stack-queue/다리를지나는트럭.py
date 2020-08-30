def solution(bridge_length, weight, truck_weights):
    answer = 0
    q = []
    cnt = 0
    nweight = 0
    i = 0
    while i < len(truck_weights):
        cnt += 1
        if nweight + truck_weights[i] <= weight:
            nweight += truck_weights[i]
            q.append([cnt,i])
            i += 1
        if bridge_length <= cnt - (q[0][0]-1):
            nweight -= truck_weights[q[0][1]]
            q.pop(0)
    answer = cnt + bridge_length 
    return answer
