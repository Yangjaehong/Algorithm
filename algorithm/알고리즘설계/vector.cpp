#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;


int main(){
    clock_t start, end;
    int n;
    double res;
    cin >> n;

    int** a = new int* [n];
    int** b = new int* [n];
    int** c = new int* [n];
    // 각각 배열의 행들을 초기화 함
    int* tmp = new int [n];
    // 곱셈 결과를 담을 배열 하나를 생성함
    for (int col = 0; col < n; col++){
        a[col] = new int[n];
        b[col] = new int[n];
        c[col] = new int[n];
    } // 그리고 각각의 행의 열 (원소) 들을 초기화해줌
    
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 50;
            b[i][j] = rand() % 30;
            c[i][j] = rand() % 10;
        } // rand 함수를 이용하여 임의의 값으로 배열을 채워줌
    }

    start = clock();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                tmp[k] = a[i][j] * b[i][j] * c[i][j];
            }
        }
    }

    end = clock();
    res = (double)(end - start);

    for (int i = 0; i < n; i++) {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];        
    }

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] tmp;

    cout << "n^3 (Cubic Complexity) 의 소요 시간: " << res << " ms" << endl;


}