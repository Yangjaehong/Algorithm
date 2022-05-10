#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

#define max 10
int n,e;
int graph[max][max];

void dfs(int node){
    bool visited[max] = {false};
    stack<int> mystack;
    mystack.push(node);

    while(!mystack.empty()){
        int curr = mystack.top();
        mystack.pop();

        if(visited[curr]) continue;

        visited[curr] = true;
        cout << curr << ' ';

        for(int next = 0; next < n; next++){
            if(!visited[next] && graph[curr][next])
                mystack.push(next);
        }

    }
}

int main(){
    cin >> n >> e;
    memset(graph,0,sizeof(graph));

    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
    dfs(0);
    cout << endl;
    return 0;
}