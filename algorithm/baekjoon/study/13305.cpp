#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n = 0; //도시의 개수
    long long sol = 0;
    cin >> n;
    vector<vector<int> > v(n-1, vector<int>(1,0)); 

    for(int i = 0; i < n-1; i++){ //도시당 거리
        int k;
        cin >> k;
        v[i][1] = k;
    }

    int cnt = 0;
    while(true) //기름 가격
    { 
        int k;
        cin >> k;
        if(cnt == n-1) break;
        v[cnt][0] = k;
        cnt++;
    }
    int j = 0;
    sol = v[j][1] * v[j][0]; //1번 도시에서 주유

    for(int i = 1; i < n-1; i++){
        if(v[j][0] > v[i][0]){
            j = i;  //더 싼것으로 하기
        }
        sol += v[i][1] * v[j][0];
    }
    cout << sol << endl;
    return 0;
}