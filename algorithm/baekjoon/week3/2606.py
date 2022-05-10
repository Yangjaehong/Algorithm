n=int(input())
t=int(input())

graph=[[0]*n for i in range(n)]
visit=[0]*n #방문여부 마킹
cnt=0

for i in range(t):
    a,b=map(int,input().split())
    graph[a-1][b-1]=graph[b-1][a-1]=1

def dfs(v):
    visit[v]=1
    for i in range(n):
        if graph[v][i]==1 and visit[i]==0:
            dfs(i)

dfs(0)

for i in range(1,n):
    if visit[i]==1:
        cnt+=1
        
print(cnt)