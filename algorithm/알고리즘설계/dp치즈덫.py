cheese = [
    [-1,-1,1,-1,-1,-1,-1,-1,-1],
    [-1,-1,-1,-1,-1,1,-1,2,-1],
    [1,-1,2,-1,-1,-1,-1,1,-1],
    [-1,-1,-1,-1,1,2,-1,-1,-1],
    [-1,1,-1,1,-1,-1,-1,-1,-1],
    [-1,-1,-1,-1,-1,2,1,2,-1],
    [-1,1,-1,-1,1,-1,-1,-1,-1],
    [-1,-1,-1,-1,-1,1,-1,-1,-1],
    [-1,-1,-1,-1,-1,-1,-1,-1,-1]
]
n = 9 #전체 크기 지정
countcheese = [[0]*n for _ in range(n)] #빈배열 선언

for i in range(1,len(cheese[n-1])): #시작할 때 제일 밑행쪽(9번째 배열쪽)으로 가는 방향은 오른쪽으로 계속가는 방법밖에 없어서 for문을 따로 빼줌
    if cheese[n-1][i] == 1: #1 즉 치즈이면 countcheese[n-1][i] 에 직전 것에 1더해서 더해줌
        countcheese[n-1][i] = countcheese[n-1][i-1] + 1 
    elif cheese[n-1][i] == -1: #-1 즉 아무것도 없으면 직전것을 그대로 가져옴
        countcheese[n-1][i] = countcheese[n-1][i-1]
    elif cheese[n-1][i] == 2: countcheese[n-1][i] = -n + 1 #덫이면 -10을 넣어버림

for i in range(len(cheese)-2,-1,-1): #시작해서 위로만 가는 방향
    if cheese[i][0] == 1:
        countcheese[i][0] = countcheese[i+1][0] + 1 #치즈이면 직전 것에 1을 더해서 저장
    elif cheese[i][0] == -1: #아무것도 없으면 직전 것을 그대로 가져옴
        countcheese[i][0] = countcheese[i+1][0] 
    elif cheese[i][0] == 2: countcheese[i][0] = -n + 1 #덫을 만나면 -10을넣어버림

for i in range(len(cheese)-2, -1, -1): #위 두가지 경우를 제외하고 다른 부분들
    for j in range(1,len(cheese[i])):
        if cheese[i][j] == 1: #치즈이면
            countcheese[i][j] = max(countcheese[i+1][j],countcheese[i][j-1]) +1 #아래행의 j번째와 같은행의 j-1번째중 큰 것에 +1을 해서 넣음
        elif cheese[i][j] == -1: #아무것도 없으면
            countcheese[i][j] = max(countcheese[i+1][j], countcheese[i][j-1]) #아래행의 j번째와 같은행의 j-1번째중 큰 것을 그대로 넣음
        elif cheese[i][j] == 2: #덫이면
            countcheese[i][j] = -n + 1 #그 자리에 -10을 넣음

print(f'최대 먹을 수 있는 치즈의 수: {countcheese[0][n-1]} 개') #출력확인 0행의 끝번째에서 결과 확인 가능

