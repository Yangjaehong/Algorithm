#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int n = 0;
    int cnt = 0;
    bool f = true;
    
    string a;
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> a;
        for(int j = 0; j < a.length(); j++)
            for(int k = 0; k < j; k++){
                if(a[j] != a[j-1] && a[j] == a[k]){
                    f = false;
                    break;
                }
            }
        if(f) cnt++;
    }
    cout << cnt << endl;
}