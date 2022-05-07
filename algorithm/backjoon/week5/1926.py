from collections import deque
 
n, m = map(int, input().split())
graph = []
 
for i in range(n):
    graph.append(list(map(int, input().split())))
 
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
 
def bfs(a, b):
    queue = deque()
    queue.append((a, b))
    graph[a][b] = 0
    global cnt
    cnt = 1
 
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if -1<nx<n and -1<ny<m and graph[nx][ny] == 1:
                graph[nx][ny] = 0
                queue.append((nx, ny))
                cnt += 1
 
area = []
for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            bfs(i, j)
            area.append(cnt)
 
 
if len(area) == 0:
    print(len(area))
    print(0)
else:
    print(len(area))
    print(max(area))