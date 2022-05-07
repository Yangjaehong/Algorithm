#include <iostream>
using namespace std;
int n, sol;
int arr[6] = {500, 100, 50, 10, 5, 1};

int main(){
    cin >> n;
    n = 1000 - n;

    for(int i = 0; i < 6; i++){
        sol += n/arr[i];
        n %= arr[i];
    }

    cout << sol << endl;
    return 0;

    

}