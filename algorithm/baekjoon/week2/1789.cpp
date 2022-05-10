#include <iostream>
using namespace std;

int main(){
    long long S = 0, sol = 0;
    int cnt = 0;
    cin >> S;
    
    while(true){
        cnt++;
        sol += cnt;
        if(S < sol){
            cnt--;
            break; 
        }
    }
    cout << cnt << endl;
    return 0;
}