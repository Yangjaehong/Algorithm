#include <iostream>
using namespace std;
int a,b;
int cnt;

int main(){
    cin >> a >> b;

    while(true){
        if (b < a) {
            cout << -1 << endl;
            break;
        }
        else if(b == a){
            cout << cnt + 1 << endl;
            break;
        }

        if(b % 2 == 0) {
            b = b/2;
        }    
        else if (b % 10 == 1){
            b = b/10;

        }
        else{
            cout << -1 <<endl;
            break;
        }
        cnt++;
    }

    return 0;

}