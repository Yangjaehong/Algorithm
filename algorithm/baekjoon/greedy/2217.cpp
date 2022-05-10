#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> a;
int main(){
    int n, sol;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x = 0;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    sol = a[0] * n;
    for(int i = 1; i < a.size(); i++){
       if(sol < a[i] * (n - i)) sol = a[i] * (n-i); 
    }
    
    cout << sol << endl;
   
}