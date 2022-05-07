#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int a = 0, b = 0;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if((str[i] == '1') && (str[i] != str[i+1])) a++;
        else if((str[i] == '0') && (str[i] != str[i+1])) b++;
    }
    if(a > b) cout << b << endl;
    else cout << a <<endl;
    return 0;
}