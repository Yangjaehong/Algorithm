#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main(){
    int n;
    cin >> n;
    vector<string> str;

    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        if(find(str.begin(), str.end(), x) == str.end())
        str.push_back(x);
    }

    sort(str.begin(), str.end(),cmp);

    for(int i = 0; i < str.size(); i++){
        cout << str[i] << endl;
    }
}