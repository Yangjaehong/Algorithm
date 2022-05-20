#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>

using namespace std;

void path(int P[6][6], int q, int r){
    if(P[q][r] != 0){
        path(P, q, P[q][r]);
        cout<<"v"<<P[q][r]<<" -> ";
        path(P, P[q][r], r);
    }
}

void floyd(int n, int D[6][6], int P[6][6]){ //floyd 알고리즘
    int i, j, k;
    int m = 0;
    for(k=1; k<=n; k++){
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                if(D[i][j] > D[i][k] + D[k][j]){
                    m = D[i][k] + D[k][j];
                    P[i][j] = k;
                } 
                else m = D[i][j];
                D[i][j] = m;
            }
        }
    }
    cout<<"D[i][j] is"<<endl;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cout<<setw(4)<<D[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"P[i][j] is"<<endl;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cout<<setw(4)<<P[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    //실습과제에서 요구한 사항을 출력하기 위하여 함수내부에 작성함
    cout<<"The shortest path(5, 3) is v5 -> ";
    path(P, 5, 3); 
    cout<<"v3"<<endl;

    cout<<"The shortest path(1, 3) is v1 -> ";
    path(P, 1, 3); 
    cout<<"v3"<<endl;

    cout<<"The shortest path(2, 5) is v2 -> ";
    path(P, 2, 5); 
    cout<<"v5"<<endl;
    
    
}

int main(){
    
    int P[6][6] = {0}; //P 배열 초기화
    
    int w[6][6] = {{0,1,2,3,4,5}, //번호를 표시하기 위함
                   {0,0,1,100,1,5}, //v1 
                   {0,9,0,3,2,100}, //v2
                   {0,100,100,0,4,100}, //v3
                   {0,100,100,2,0,3},   //v4
                   {0,3,100,100,100,0}}; //v5
                   //각각에 못가는 곳은 큰수를 넣음

    cout<<"w array"<<endl;
    for(int i=0; i<6; i++){ //w배열을 출력하기 위한 for문
        for(int j=0; j<6; j++){
            cout<<setw(4)<<w[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    
    floyd(5,w,P); 
    return 0;
}