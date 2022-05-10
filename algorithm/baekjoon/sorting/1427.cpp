#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int cmp(int a, int b){
    return a > b;
}

int main(){
    string str;
    cin >> str;
    sort(str.begin(), str.end(), cmp);
    cout << str << endl;

}