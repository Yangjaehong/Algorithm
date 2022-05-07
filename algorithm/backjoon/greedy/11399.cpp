#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> a;

int main(){
    int sol = 0, n;

    cin >> n;

    for(int i =0; i < n; i++){
        int x =0;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    int m = 0;
    
    while(true){
        for(int i =0; i < (m+1); i++){
            sol += a[i];
        }
        m++;
        if(m == n) break;
    }

    cout << sol << endl;


    return 0;
}