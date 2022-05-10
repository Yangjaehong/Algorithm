#include <iostream>
#include <string>
using namespace std;

int main(){
    int n,k;
    string a;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        cin >> a;
        for(int j = 0; j < a.length(); j++){
            for(int m = 0; m < k; m++){
                cout << a[j];
            }
        }
        cout << endl;
    }
    return 0;
}