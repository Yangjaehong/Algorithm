#include <iostream>
#include <cstring>

using namespace std;

#define max 10 //조건에 따라 맥스값 변경
int n,e; //n = 노드의 개수, e = 간선의 개수
int graph[max][max];
bool visited[max]; //방문여부 마킹

void dfs(int node){
    visited[node] = true; //방문 했다
    cout << node << ' '; //방문 한 것 출력

    for(int next = 0; next < n; next++){
        if(!visited[next] && graph[node][next])
        dfs(next);
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
    dfs(0);
    cout << endl;
    return 0;
}