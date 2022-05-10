#include <iostream>
using namespace std;

int n,m;
int map[1001][1001];

bool dfs(int x, int y){
    if(x <= -1 || x >= n || y <= -1 || y >= m){
        return false;
    }

    if(map[x][y] == 0){
        map[x][y] = 1;

        dfs(x-1, y);
        dfs(x, y-1);
        dfs(x+1, y);
        dfs(x, y+1);
        return true;
    }

    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (dfs(i,j)){
                result += 1;
            }
        }
    }
    cout << result << endl;
}