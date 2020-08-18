def solution(progresses, speeds):
    Q = []
    for p,s in zip(progresses, speeds):
        if ((100 - p) % s) != 0:
            day = (100 - p)//s + 1
        else:
            day = (100 - p)//s
        if len(Q) == 0 or Q[-1][0] < day:
            Q.append([day, 1])
        else:
            Q[-1][1] += 1
    return [q[1] for q in Q]
