#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000000

int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
    int n, m;
    cin >> n >> m;
    memset(visited,0, sizeof(visited));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    return 0;
}