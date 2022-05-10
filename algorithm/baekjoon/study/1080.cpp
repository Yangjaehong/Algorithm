#include <iostream>
#include <algorithm>
using namespace std;
 
int a[50][50];
int b[50][50];
 
void change(int y, int x) {
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            a[i][j] = 1 - a[i][j];
        }
    }
}
int main()
{
    int n, m; 
    char k;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> k;
            a[i][j] = k - 48; 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> k;
            b[i][j] = k - 48; 
        }
    }

    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (a[i][j] != b[i][j]) {
                cnt++;
                change(i + 1, j + 1);
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                cnt = -1;
            }
        }
    }
    cout << cnt;
    return 0;
}
