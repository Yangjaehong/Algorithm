import sys
sys.setrecursionlimit(10000)
input=sys.stdin.readline

n,m=map(int,input().split())

graph=[[0]*(n+1) for i in range(n+1)]
visit=[0]*(n+1)

for i in range(m):
    a,b=map(int,input().split())
    graph[a][b]=graph[b][a]=1

def dfs(v):
    visit[v]=1
    for i in range(1,n+1):
        if graph[v][i]==1 and visit[i]==0:
            dfs(i)

cnt=0
for i in range(1,n+1):
    if visit[i]==0:
        dfs(i)
        cnt+=1
print(cnt)