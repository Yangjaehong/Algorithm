#include <string>
#include <iostream>
using namespace std;

int n,sol;
int main(){
    cin >> n;
    char a;

    for(int i = 0; i < n; i++){
        cin >> a;
        sol = sol + (a-'0');
    }

    cout << sol << endl;
}