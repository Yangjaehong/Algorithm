n = int(input())

dx = [0,0,1,-1]
dy = [1,-1,0,0]

graph = []

for i in range(n):
    graph.append(list(map(int, input())))

def dfs(x,y):
    if x < 0 or x >= n or y < 0 or y >= n:
        return False
    
    if graph[x][y] == 1:
        graph[x][y] = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            dfs(nx,ny)
        global cnt
        cnt += 1
        return True
    return False 


cnt = 0
k = []
for i in range(n):
    for j in range(n):
        if dfs(i,j) == True:
            k.append(cnt)
            cnt = 0

print()
k = sorted(k)
print(len(k))
for i in range(len(k)):
    print(k[i])