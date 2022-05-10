#include <iostream>
using namespace std;

int main(){
    int n = 0, cnt = 0;
    cin >> n;
    if(n < 100) cout << n <<endl;
    else{
        for(int i = 100; i < n+1; i++){
            int a, b, c;
            a = i / 100;
            b = (i % 100) / 10;
            c = (i % 100) % 10;
            if((a - b) == (b - c)) cnt++;
        }
        cout << cnt + 99 << endl;
    }
    return 0;
}