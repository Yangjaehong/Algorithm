#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000000

int n = 0, m = 0, o = 0, v = 0, oo = 0, vv = 0;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool range(int x, int y){
    return y >= 0 && x >= 0 && y < m && x < n;
}

void dfs (int x, int y){
    visited[x][y] = true;
    if(map[x][y] == 'o') o++;
    if(map[x][y] == 'v') v++;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
    
        if (range(nx,ny) && map[nx][ny] != '#' && visited[nx][ny] == 0) {
            dfs(nx, ny);
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
   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == 0 && map[i][j] != '#')
            dfs(i,j);
            if(o > v) oo += o;
            else if (v >= o) vv += v;
            v = 0;
            o = 0;
        }
    }
    cout << oo  << ' ' << vv << endl;

    return 0;
}