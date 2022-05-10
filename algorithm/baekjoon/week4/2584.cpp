#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define max 100

int map[max][max];
bool visited[max][max];
int x1[max], y1[max], x2[max], y2[max];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int m = 0, n = 0, k = 0, sol = 1;

void dfs(int x, int y){
    visited[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(!visited[nx][ny] && nx >= 0 && ny >= 0 && nx < n && ny < m){
            dfs(nx,ny);
            sol++;
        }
    }
}
int main(){
    memset(visited, 0, sizeof(visited));
    memset(map, 0, sizeof(map));
    int cnt = 0;
    cin >> m >> n >> k;

    //0 2 4 4 앞이 x 뒤가 y
    for(int i = 0; i < k; i++){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        for(int j = x1[i]; j < x2[i]; j++){
            for(int p = y1[i]; p < y2[i]; p++){
                visited[j][p] = 1; // x,y
            }
        }
        
    }
    vector <int> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]){
                sol = 1;
                dfs(i,j);
                cnt++;
                v.push_back(sol);
            }
        }

    }

    sort(v.begin(), v.end());
    cout << cnt << " ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i]  << " " ;
    }
    cout << endl;
}

    
    
