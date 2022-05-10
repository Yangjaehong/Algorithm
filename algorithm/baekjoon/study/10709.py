n, m = map(int, input().split())

graph = [input() for _ in range(n)] #2차원 배열 입력받기
sol = [[-1] * m for _ in range(n)] #2차원 배열 초기화


for i in range(n):
    for j in range(m):
        if graph[i][j] == 'c': 
            sol[i][j] = 0
            k = 0
            for p in range(j+1,m):
                k += 1
                sol[i][p] = k

        elif graph[i][j] == '.' and sol[i][j] == -1: 
            continue

for i in sol:
    print(*i) # *로 원소만 출력