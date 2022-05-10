#include <iostream>
#include <cstring>

using namespace std;

#define max 100
int n;
char map[max][max];
bool visited[max][max];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void reset(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            map[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void dfs(int x, int y){
    visited[x][y] = 1;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(map[nx][ny] == map[x][y] && visited[nx][ny] == 0){
            dfs(nx,ny);
        }
    }
}

int main(){
    cin >> n;
    reset();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                dfs(i,j);
                count++;
            }
        }
    }
    cout << count <<" ";
    count = 0;
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 'G') map[i][j] = 'R';
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                dfs(i,j);
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}