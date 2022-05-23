def solution(absolutes, signs):
    answer = 0
    for i in range(len(absolutes)):
        if not signs[i]:
            answer -= absolutes[i]
        else: answer += absolutes[i]
    return answer