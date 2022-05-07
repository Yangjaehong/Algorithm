#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> a;
    int n = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << ' ';
    }
    cout <<endl;
    return 0;
}