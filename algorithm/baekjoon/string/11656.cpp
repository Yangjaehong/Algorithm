#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string a[1000];
    string s;
    cin >> s;
    int m = s.size();

    for(int i = 0; i < s.size(); i++){
        for(int j = i; j < s.size(); j++){
            a[i] += s[j];
        }
    }

    sort(a,a+m);
    for(int i = 0; i < m; i++) cout << a[i] << endl; 
}