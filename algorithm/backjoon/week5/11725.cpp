#include <iostream>
#include <cstring>
using namespace std;
#define max 1001 //조건에 따라 맥스값 변경
int n,e,cnt = 0; //n = 노드의 개수, e = 간선의 개수
int graph[max][max];
bool visited[max]; //방문여부 마킹

void dfs(int node){
    visited[node] = true; //방문 했다

    for(int i = 1; i < n+1; i++){
        if(!visited[i] && graph[node][i]){
            dfs(i);
        }
    }
}

int main(){
    cin >> n >> e;
    memset(visited,0, sizeof(visited));
    memset(graph, 0, sizeof(graph)); //간선을 모두 못간다고 초기화
    for(int i = 0; i < e; i++){
        int u,v;
        cin >> u >> v; 
        graph[u][v] = graph[v][u] = 1; //u에서 v = v에서 u = 갈 수 있음 (쌍방향)
    }
    int cnt = 0;
    for(int i = 1; i < n+1; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt <<endl;
    return 0;
}