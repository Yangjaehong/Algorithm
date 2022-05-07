#include <iostream>
#include <cstring>
using namespace std;

#define max 250
int map[max][max];
bool visited[max][max];
int n, m;
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};

void dfs(int x, int y){
    visited[x][y] = true;

    for(int i = 0; i < 8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
    
        if (ny < 0 || nx < 0 || ny >= m || nx >= n) 
            continue;
        if (map[nx][ny] == 1 && !visited[nx][ny]){
            dfs(nx,ny);
        }
    }
}


int main(){
    cin >> n >> m;
    memset(visited,0, sizeof(visited));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && map[i][j] == 1){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}