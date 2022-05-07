#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define max 25
bool visited[max][max];
int map[max][max];
int n, k;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void reset(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

bool range(int x, int y){
    return y >= 0 && x >= 0 && y < n && x < n;
}

void dfs(int x, int y){
    visited[x][y] = 1;
    k += 1;

     for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(visited[nx][ny] == 0 && range(nx,ny) && map[nx][ny] == 1){
            dfs(nx,ny);
        }

     }
    
}
int main(){
    cin >> n;
    reset(n);
   
    int count = 0;
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        for(int j = 0; j < n; j++){
            map[i][j] += a[j] - '0';
        }
    }

    vector<int> arr;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 0 && map[i][j] == 1){
                k = 0;
                dfs(i,j);
                count++;
                arr.push_back(k);
            }
        }
    }


    cout << count << endl;
    sort(arr.begin(),arr.end());
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }
    return 0;
}