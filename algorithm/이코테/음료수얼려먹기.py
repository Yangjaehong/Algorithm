n,m = map(int, input().split())

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

def DFS(x,y):
    if x < 0 or x >= n or y < 0 or y >= m:
        return False

    if graph[x][y] == 0:
        graph[x][y] = 1
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            DFS(nx,ny)
        return True
    return False

sol = 0
for i in range(n):
    for j in range(m):
        if DFS(i,j) == True:
            sol += 1
print(sol)