#include <iostream>
#include <cstring>
#include <stack>

#define max 10
using namespace std;
void dfs(int, int, int);

struct point{
    int row, col;
};

int d[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int n, board[max][max];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    
    int sr, sc, color;
    cin >> sr >> sc >> color;
    dfs(sr, sc, color);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

void dfs(int r, int c, int color){
    bool visited[max][max] = {false};

    stack<point> mystack;
    // mystack.push({r,c});

}