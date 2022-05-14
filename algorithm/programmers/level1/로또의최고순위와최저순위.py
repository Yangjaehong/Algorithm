def solution(lottos, win_nums):
    answer = [0,0]
    rank = [6,6,5,4,3,2,1]
    cnt = 0
    x = lottos.count(0)
    for i in lottos:
        for j in win_nums:
            if i == j: cnt += 1
    
    answer[0], answer[1] = rank[cnt+x], rank[cnt]
    return answer