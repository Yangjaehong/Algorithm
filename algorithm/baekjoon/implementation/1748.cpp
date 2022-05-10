#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n = 0, sol = 0;
    cin >> n;
    for(int i = 1; i < n; i *= 10)
        sol += n - i + 1;

        cout << n;
    return 0;
}