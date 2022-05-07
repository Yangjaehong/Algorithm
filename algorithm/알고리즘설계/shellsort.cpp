#include <iostream>
#include <algorithm>
#include <ctime>
#include <time.h>
using namespace std;

void ShellSort(int a[], int n)
{
   int h = 1;   //shellsort 간격
   int i;
   for (; h < n; h = 3 * h + 1){}    // n보다 작아야 함,3 * gap + 1 증가
   h /= 3;    // 마지막 h는 3배이후에 
   for (; h >= 1; h /= 3){    // 3배 감소
      for (i = h; i <= n; i++){ //기존 정렬 알고리즘
         int v = a[i];
         int j = i;
         while (j >= h && a[j - h] > v){
            a[j] = a[j - h];
            j -= h;
         }
         a[j] = v;
      }
   }
}

void checkSort(int a[], int n){ //checkSort
   int i, sorted;
   sorted = true;
   for (i = 1; i <= n; i++){
      if (a[i-1] > a[i]){ //기존 코드로 진행하면 범위가 벗어나서 i-1과 i를 비교시킴
         sorted = false;
      }
      if (!sorted){
         break;
      }
   }
   if (sorted){
      printf("정렬 완료.\n");
   }
   else{
      printf("정렬 오류!!\n");
   }
}

int main(){
    srand((unsigned int)time(0)); //srand
    int n[] = {100000, 500000, 1000000, 5000000, 10000000};
    
    for(int j = 0; j < 5; j++){
        int* arr = new int[n[j]]; //동적할당

    for (int i = 0; i < n[j]; i++){ //랜덤값 배열에 넣어줌
        arr[i] = rand() % n[j];
    }

    clock_t start, end; //시간을 위한 변수 선언
    
    start = clock(); //시작시간
    ShellSort(arr, n[j]); //쉘정렬 시작
    end = clock();  //끝시간
    double timeSecond = (double)((end-start) / double(CLOCKS_PER_SEC)); //초단위로 표현하기 위함
    cout.precision(4); //숫자 네개 만나오게 함
    cout << "증가식: 3h+1, 감소식: h/3, 쉘 정렬 실행 시간 (N = " << n[j] << "):" << timeSecond << "sec" << endl;
    checkSort(arr, n[j]);
    delete[] arr;
    }
    
    return 0;
}