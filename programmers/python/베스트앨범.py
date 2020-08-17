def solution(genres, plays):
    answer = []
    genreNum = {}
    dict = {}
    for i in range(len(genres)):
        if genres[i] in dict:
            genreNum[genres[i]] += plays[i]
            dict[genres[i]].append([plays[i], i])
        else:
            genreNum[genres[i]] = plays[i]
            dict[genres[i]] = []
            dict[genres[i]].append([plays[i], i])

    genreNum = sorted(genreNum.items(), key = lambda x:-x[1])

    for genre in genreNum:
        songList = dict[genre[0]]
        songList.sort(key = lambda x:-x[0])
        if(len(songList) == 1):
            answer.append(songList[0][1])
        else:   
            answer.append(songList[0][1])
            answer.append(songList[1][1])
    return answer
