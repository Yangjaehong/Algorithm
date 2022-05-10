#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(int a, int b){
    return a > b;
}

int main(){
    vector<int> a;
    int n = 0, max = 0, sol = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(),a.end(),cmp);
    for(int i = 0; i < a.size(); i++){
        sol = a[i] + (2+i);
        if(sol > max) max = sol;
    }
    cout << max << endl;

}