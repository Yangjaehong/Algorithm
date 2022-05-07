#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50

int map[MAX][MAX];
bool visited[MAX][MAX];
int N, M;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool range(int x, int y){
    return y >= 0 && x >= 0 && y < M && x < N;
}

void reset() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void dfs (int x, int y){
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
    
        if (range(nx,ny) && map[nx][ny] == 1 && visited[nx][ny] == 0) {
            dfs(nx, ny);
        }
    }
}

int main(){
    int K, count, t, c = 0;

    cin >> t;
    while(true){
        count = 0;
        cin >> N >> M >> K;
        reset();
        for(int i = 0; i < K; i++){
            int x,y;
            cin >> x >> y;
            map[x][y] = 1;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(visited[i][j] == 0 && map[i][j] == 1){
                    dfs(i,j);
                    count++;
                }
            }
        }
        cout << count << endl;
        c++;
        
        if(t == c) break;
    }
    return 0;
}