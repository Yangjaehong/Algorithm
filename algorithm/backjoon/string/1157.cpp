#include <iostream>
#include <string>

using namespace std;

int main(){
    string a;
    int max = 0, index, count;
    int arr[26] = {0, }; //알파벳 개수 카운트
    cin >> a;

    for(int i = 0; i < a.length(); i++){
       int n = a[i];
       if (n < 97) arr[n-65]++; //대문자면 
       else arr[n-97]++; 
    }

    for(int i = 0; i<26; i++){
        if(arr[i] > max){
            max = arr[i];
            index = i;
        }
    }

    for(int i=0; i<26; i++){
        if(arr[i] == max){
            count++;
        }
    }
    if(count >= 2){
        cout << "?"  <<endl;
        
    }
    else cout << (char)(index+65) <<endl;

    
    return 0;
}