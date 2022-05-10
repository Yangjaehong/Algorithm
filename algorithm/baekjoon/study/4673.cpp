#include <iostream>
#include <cstring>
using namespace std;

int main(){
    
    bool a[10001];
    memset(a,0, sizeof(a));
    for(int i = 1; i < 10001; i++){
        int num = 0;
        if(i < 10){
            num = i + i;
            a[num] = true;
        }
        else if(i < 100){
            num = i + (i % 10) + (i / 10);
            a[num] = true;
        }
        else if(i < 1000){
            int k = 0;
            num = i + (i/100);
            k = i % 100;
            num += ((k / 10) + (k % 10));
            a[num] = true;
        }
        else if(i < 10000){
            int k = 0, j = 0;
            num = i + (i/1000);
            k = i % 1000;
            num += k / 100;
            j = k % 100;
            num += ((j / 10) + (j % 10));
            a[num] = true;
        }
    }

    for(int i = 1; i < 10001; i++){
        if(a[i] == false){
            cout << i << endl;
        }
    }
    return 0;
}