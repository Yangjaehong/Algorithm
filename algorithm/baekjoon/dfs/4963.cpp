#include <iostream>
using namespace std;
 
const int MAX = 50;
int w, h;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
 
void reset() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}
 
void DFS(int x, int y) {
    visited[x][y] = true;
 
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
 
        if (ny < 0 || nx < 0 || ny >= h || nx >= w)
            continue;
        if (map[nx][ny] == 1 && visited[nx][ny] == 0) {
            DFS(nx, ny);
        }
    }
}
 
int main() {
    while (true) {
        reset();
 
        cin >> w >> h;
 
        if (w == 0 && h == 0) {
            break;
        }
 
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
 
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1 && visited[i][j] == 0) {
                    DFS(i, j);
                    cnt++;
                }
            }
        }
 
        cout << cnt << endl;
 
    }
 
}
